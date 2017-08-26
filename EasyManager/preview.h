#ifndef PIEVIEW_H
#define PIEVIEW_H

#include <QAbstractItemView>

class PieView : public QAbstractItemView
{
    Q_OBJECT
public:
    explicit PieView(QWidget *parent = 0);
    QModelIndex indexAt(const QPoint &point) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
    QRect visualRect(const QModelIndex &index) const;

signals:

public slots:
protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void rowsInserted(const QModelIndex &parent, int start, int end);
    void rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent * /* event */);
    bool isIndexHidden(const QModelIndex &index) const;
    QRegion itemRegion(const QModelIndex &index) const;
    int horizontalOffset() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction,
                                    Qt::KeyboardModifiers /*modifiers*/);
    bool PieView::edit(const QModelIndex &index, EditTrigger trigger, QEvent *event);
    void setSelection(const QRect&, QItemSelectionModel::SelectionFlags command);
    void scrollContentsBy(int dx, int dy);
    int verticalOffset() const;
    QRegion visualRegionForSelection(const QItemSelection &selection) const;

private:
    int margin, totalSize, pieSize;
    int validItems;
    double totalValue;
    QPoint origin;
    QRubberBand *rubberBand;

    QRect itemRect(const QModelIndex &item) const;
    int rows(const QModelIndex &index = QModelIndex()) const;
    void updateGeometries();

};

#endif // PIEVIEW_H
