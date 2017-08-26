#include "pieview.h"
#include <QtGui>
#include <QtCore>

#ifndef M_PI
#define M_PI 3.1415927
#endif

PieView::PieView(QWidget *parent) :
    QAbstractItemView(parent)
{
    horizontalScrollBar()->setRange(0 ,0);//设置水平拖动条范围
    verticalScrollBar()->setRange(0, 0);//设置垂直拖动条范围

    margin = 8;
    totalSize= 230;
    pieSize = totalSize - 2*margin;
    validItems = 0;
    totalValue = 0.0;
}

//这是个槽函数,当视图数据改变时调用
void PieView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    QAbstractItemView::dataChanged(topLeft, bottomRight);//当数据被改变时改变这个槽函数

    validItems = 0;//有效的item数目
    totalValue = 0.0;//总销售量
    for (int row = 0; row < model()->rowCount(rootIndex()); ++row)
    {
        QModelIndex index = model()->index(row, 1, rootIndex());//按顺序进行索引
        double value = model()->data(index).toDouble();//对应索引的销售量
        if(value > 0.0)
        {
            totalValue += value;//即统计总销售量和有效条目
            validItems ++;
        }

    }
    viewport()->update(); //视图更新
}


//该函数是当当前所选的item处于可编辑状态时对应的编辑操作
bool PieView::edit(const QModelIndex &index, EditTrigger trigger, QEvent *event)
{
    if( index.column() == 0)
        return QAbstractItemView::edit(index, trigger, event);
    else
        return false;
}


QModelIndex PieView::indexAt(const QPoint &point) const
{
    if( validItems == 0)
        return QModelIndex();
    int wx = point.x() + horizontalScrollBar()->value();
    int wy = point.y() + verticalScrollBar()->value();

    if(wx < totalSize)
    {
        double cx = wx - totalSize/2;
        double cy = totalSize/2 - wy;

        double d = pow(pow(cx, 2) + pow(cy, 2), 0.5);//求2点之间的欧式距离
        if(d == 0 || d > pieSize/2)
            return QModelIndex();

        double angle = (180/ M_PI)* acos(cx/d);//角度
        if(cy < 0)
            angle = 360 - angle;
        double startAngle = 0;//起始角度
        for(int row = 0; row < model()->rowCount(rootIndex()); ++row)
        {
            QModelIndex index = model()->index(row, 1, rootIndex());
            double value = model()->data(index).toDouble();
            if(value > 0.0)
            {
                double sliceAngle = 360*value/totalValue;
                if(angle > startAngle && angle < (sliceAngle + startAngle))
                    return model()->index(row, 1, rootIndex());
                startAngle += sliceAngle;
            }
        }
    }
    else
    {
        double itemHeight = QFontMetrics(viewOptions().font).height();
        int listItem = int((wy - margin) / itemHeight);
        int validRow = 0;

        for (int row = 0; row < model()->rowCount(rootIndex()); ++row) {

            QModelIndex index = model()->index(row, 1, rootIndex());
            if (model()->data(index).toDouble() > 0.0) {

                if (listItem == validRow)
                    return model()->index(row, 0, rootIndex());

                validRow++;
            }
        }
    }
    return QModelIndex();
}


//判断索引是否隐藏
bool PieView::isIndexHidden(const QModelIndex &index) const
{
    return false;
}


QRect PieView::itemRect(const QModelIndex &index) const
{
    if(!index.isValid())
        return QRect();
    QModelIndex valueIndex;
    if(index.column() != 1)
        valueIndex = model()->index(index.row(), 1, rootIndex());
    else
        valueIndex = index;
    if(model()->data(valueIndex).toDouble()> 0.0)
    {
        int listItem = 0;
        for(int row = index.row()-1; row>-0; --row)
        {
            if(model()->data(model()->index(row, 1, rootIndex())).toDouble()>0.0)
                listItem++;
        }
        double itemHeight;
        switch(index.column())
        {
            case 0:
            itemHeight = QFontMetrics(viewOptions().font).height();//获取字体的高度
            return QRect(totalSize, int(margin + listItem*itemHeight),
                         totalSize - margin, int(itemHeight));
            case 1:
                return viewport()->rect();
        }
    }
    return QRect();
}

QRegion PieView::itemRegion(const QModelIndex &index) const
{
    if (!index.isValid())
        return QRegion();

    if (index.column() != 1)
        return itemRect(index);

    if (model()->data(index).toDouble() <= 0.0)
        return QRegion();

    double startAngle = 0.0;
    for (int row = 0; row < model()->rowCount(rootIndex()); ++row) {

        QModelIndex sliceIndex = model()->index(row, 1, rootIndex());
        double value = model()->data(sliceIndex).toDouble();

        if (value > 0.0) {
            double angle = 360*value/totalValue;

            if (sliceIndex == index) {
                QPainterPath slicePath;
                slicePath.moveTo(totalSize/2, totalSize/2);
                slicePath.arcTo(margin, margin, margin+pieSize, margin+pieSize,
                                startAngle, angle);
                slicePath.closeSubpath();

                return QRegion(slicePath.toFillPolygon().toPolygon());
            }

            startAngle += angle;
        }
    }

    return QRegion();
}


int PieView::horizontalOffset() const
{
    return horizontalScrollBar()->value();
}


//鼠标按下时的反应处理
void PieView::mousePressEvent(QMouseEvent *event)
{
    QAbstractItemView::mousePressEvent(event);
    origin = event->pos();
    if (!rubberBand)
        //QRubberBand为设置橡皮筋框
        rubberBand = new QRubberBand(QRubberBand::Rectangle, viewport());
    rubberBand->setGeometry(QRect(origin, QSize()));
    rubberBand->show();
}


//鼠标移动时的处理
void PieView::mouseMoveEvent(QMouseEvent *event)
{
    if (rubberBand)
        rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
    QAbstractItemView::mouseMoveEvent(event);
}

//鼠标释放时的处理
void PieView::mouseReleaseEvent(QMouseEvent *event)
{
    QAbstractItemView::mouseReleaseEvent(event);
    if (rubberBand)
        rubberBand->hide();
    viewport()->update();
}

//光标移动时的处理
QModelIndex PieView::moveCursor(QAbstractItemView::CursorAction cursorAction,
                                Qt::KeyboardModifiers /*modifiers*/)
{
    QModelIndex current = currentIndex();

    switch (cursorAction) {
        case MoveLeft:
        case MoveUp://向左和向上处理效果一样
            if (current.row() > 0)
                current = model()->index(current.row() - 1, current.column(),
                                         rootIndex());
            else
                current = model()->index(0, current.column(), rootIndex());
            break;
        case MoveRight:
        case MoveDown://向下和向右处理效果一样
            if (current.row() < rows(current) - 1)
                current = model()->index(current.row() + 1, current.column(),
                                         rootIndex());
            else
                current = model()->index(rows(current) - 1, current.column(),
                                         rootIndex());
            break;
        default:
            break;
    }

    viewport()->update();
    return current;
}


void PieView::paintEvent(QPaintEvent *event)
{
    QItemSelectionModel *selections = selectionModel();//selectionModel()为返回当前的选择模型
    QStyleOptionViewItem option = viewOptions();//返回一个带有填充视图的调试版，字体，对齐方式等熟悉的QStyleOptionViewItem结构
    QBrush background = option.palette.base();//获得调色版的背景色
    QPen foreground(option.palette.color(QPalette::WindowText));//定义一个用于前景色的画笔
    QPainter painter(viewport());//设置绘图类
    painter.setRenderHint(QPainter::Antialiasing);//设置渲染属性，这里设置为使用抗锯齿效果绘图
    painter.fillRect(event->rect(), background);//用背景色填充矩形
    painter.setPen(foreground);//设置画笔的前景色

    QRect pieRect = QRect(margin, margin, pieSize, pieSize);//该矩形用来画饼状图和饼状图旁边的图示的

    //开始绘制饼图
    if(validItems > 0)
    {
        painter.save();//保存绘图类
        //translate()为将坐标系移动
        //如果滑动条向右移，那么坐标系需向左移动
        painter.translate(pieRect.x()-horizontalScrollBar()->value(), pieRect.y()-verticalScrollBar()->value());
        painter.drawEllipse(0, 0, pieSize, pieSize);//在指定的矩形中画椭圆，两者的中心重合，椭圆长短轴和矩形的长宽对应起来
        double startAngle = 0.0;
        int row;
        //model()为返回当前视图的model
        for(row = 0; row < model()->rowCount(rootIndex()); ++row)
        {
            //rootIndex()为model的根索引
            QModelIndex index = model()->index(row, 1, rootIndex());//销量索引，即后面单击销售数量那一列能用到
            double value = model()->data(index).toDouble();//通过索引获取销售量
            if(value > 0)
            {
                double angle = 360*value/totalValue;
                QModelIndex colorIndex = model()->index(row, 0, rootIndex());//颜色栏索引号
                QColor color = QColor(model()->data(colorIndex, Qt::DecorationRole).toString());//获取表中的颜色
                if(currentIndex() == index)//currentIndex为当前模型的item
                    painter.setBrush(QBrush(color, Qt::Dense4Pattern));//为画图类设置画刷，其中Qt::Dense4Pattern为画笔的样式
                else if(selections->isSelected(index))
                    painter.setBrush(QBrush(color, Qt::Dense3Pattern));//所选的行用另一种样式表示
                else
                    painter.setBrush(QBrush(color));//其它的没选中的用它原来的颜色显示
                painter.drawPie(0, 0, pieSize, pieSize, int(startAngle*16), int(angle*16));//绘制饼图
                startAngle += angle;
            }
        }
        painter.restore();//保存绘画设置

        //绘制饼图旁边的图示
        int keyNumber = 0;
        for(row = 0; row < model()->rowCount(rootIndex()); ++row)
        {
            QModelIndex index = model()->index(row, 1, rootIndex());
            double value = model()->data(index).toDouble();//取出销售数量值
            if(value > 0.0)
            {
                QModelIndex labelIndex = model()->index(row, 0, rootIndex());//以第0列为索引
                QStyleOptionViewItem option = viewOptions();
                option.rect = visualRect(labelIndex);//返回虚拟的矩形，即被占住的矩形也能显示
                if(selections->isSelected(labelIndex))
                    option.state |= QStyle::State_Selected;//用于指定该widget是否被选中
                if(currentIndex() == labelIndex)
                    option.state |= QStyle::State_HasFocus;//用于指定该widget是否有焦点
                itemDelegate()->paint(&painter, option, labelIndex);//itemDelegate()类为Qt中的代理类
                keyNumber ++;
            }


        }
    }

}



//改变几何形状
void PieView::resizeEvent(QResizeEvent * /* event */)
{
    updateGeometries();
}


//返回父级index的行数
int PieView::rows(const QModelIndex &index) const
{
    return model()->rowCount(model()->parent(index));
}


//插入行
void PieView::rowsInserted(const QModelIndex &parent, int start, int end)
{
    for (int row = start; row <= end; ++row) {

        QModelIndex index = model()->index(row, 1, rootIndex());
        double value = model()->data(index).toDouble();

        if (value > 0.0) {
            totalValue += value;
            validItems++;
        }
    }

    QAbstractItemView::rowsInserted(parent, start, end);//调用父类的方法
}


//删除行
void PieView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end)
{
    for (int row = start; row <= end; ++row) {

        QModelIndex index = model()->index(row, 1, rootIndex());
        double value = model()->data(index).toDouble();
        if (value > 0.0) {
            totalValue -= value;
            validItems--;
        }
    }

    QAbstractItemView::rowsAboutToBeRemoved(parent, start, end);//调用父类的方法
}

//滑动条移动
void PieView::scrollContentsBy(int dx, int dy)
{
    viewport()->scroll(dx, dy);
}


void PieView::scrollTo(const QModelIndex &index, ScrollHint)
{
    QRect area = viewport()->rect();
    QRect rect = visualRect(index);

    if (rect.left() < area.left())
        horizontalScrollBar()->setValue(
            horizontalScrollBar()->value() + rect.left() - area.left());
    else if (rect.right() > area.right())
        horizontalScrollBar()->setValue(
            horizontalScrollBar()->value() + qMin(
                rect.right() - area.right(), rect.left() - area.left()));

    if (rect.top() < area.top())
        verticalScrollBar()->setValue(
            verticalScrollBar()->value() + rect.top() - area.top());
    else if (rect.bottom() > area.bottom())
        verticalScrollBar()->setValue(
            verticalScrollBar()->value() + qMin(
                rect.bottom() - area.bottom(), rect.top() - area.top()));

    update();
}

void PieView::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command)
{

    QRect contentsRect = rect.translated(
                            horizontalScrollBar()->value(),
                            verticalScrollBar()->value()).normalized();

    int rows = model()->rowCount(rootIndex());
    int columns = model()->columnCount(rootIndex());
    QModelIndexList indexes;

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            QModelIndex index = model()->index(row, column, rootIndex());
            QRegion region = itemRegion(index);
            if (!region.intersect(contentsRect).isEmpty())
                indexes.append(index);
        }
    }

    if (indexes.size() > 0) {
        int firstRow = indexes[0].row();
        int lastRow = indexes[0].row();
        int firstColumn = indexes[0].column();
        int lastColumn = indexes[0].column();

        for (int i = 1; i < indexes.size(); ++i) {
            firstRow = qMin(firstRow, indexes[i].row());
            lastRow = qMax(lastRow, indexes[i].row());
            firstColumn = qMin(firstColumn, indexes[i].column());
            lastColumn = qMax(lastColumn, indexes[i].column());
        }

        QItemSelection selection(
            model()->index(firstRow, firstColumn, rootIndex()),
            model()->index(lastRow, lastColumn, rootIndex()));
        selectionModel()->select(selection, command);
    } else {
        QModelIndex noIndex;
        QItemSelection selection(noIndex, noIndex);
        selectionModel()->select(selection, command);
    }

    update();
}

void PieView::updateGeometries()
{
    horizontalScrollBar()->setPageStep(viewport()->width());
    horizontalScrollBar()->setRange(0, qMax(0, 2*totalSize - viewport()->width()));
    verticalScrollBar()->setPageStep(viewport()->height());
    verticalScrollBar()->setRange(0, qMax(0, totalSize - viewport()->height()));
}

int PieView::verticalOffset() const
{
    return verticalScrollBar()->value();
}


QRect PieView::visualRect(const QModelIndex &index) const
{
    QRect rect = itemRect(index);
    if (rect.isValid())
        return QRect(rect.left() - horizontalScrollBar()->value(),
                     rect.top() - verticalScrollBar()->value(),
                     rect.width(), rect.height());
    else
        return rect;
}

QRegion PieView::visualRegionForSelection(const QItemSelection &selection) const
{
    int ranges = selection.count();

    if (ranges == 0)
        return QRect();

    QRegion region;
    for (int i = 0; i < ranges; ++i) {
        QItemSelectionRange range = selection.at(i);
        for (int row = range.top(); row <= range.bottom(); ++row) {
            for (int col = range.left(); col <= range.right(); ++col) {
                QModelIndex index = model()->index(row, col, rootIndex());
                region += visualRect(index);
            }
        }
    }
    return region;
}
