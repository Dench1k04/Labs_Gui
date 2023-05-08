#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include<QMenuBar>
#include<QToolBar>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:

    QAction* openImageAction;
    QAction* saveImageAction;
    QAction* mirrorImageAction;
    QAction* chooseColorAction;
    QAction* chooseThicknessAction;
    QLabel* imageLabel;

    QMenu* fileMenu;
    QToolBar* fileToolBar;

    QList<QList<int>> coordinatesX;
    QList<QList<int>> coordinatesY;
    int currentPolygon = -1;

    QPixmap pixMap;
    int coordinateX;
    int coordinateY;
    QColor color = Qt::red;
    int thickness = 10;

    bool doPaint = true;
    bool paint = false;
    bool dot = true;

    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);

    void openImageClick();
    void saveImageClick();
    void mirrorImageClick();
    void chooseColorClick();
    void chooseThicknessClick();

    void createActions();
    void createMenus();
    void createToolBar();

};
#endif // MAINWINDOW_H
