#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(1000, 500);
    imageLabel = new QLabel(this);
    imageLabel->setGeometry(0,0,width(), height());
    createActions();
    createMenus();
    createToolBar();
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    if (e->isInputEvent() && !paint)
        return;

    for (int i = 0; i < coordinatesX.size(); i++)
    {
        QImage image(pixMap.toImage());
        QPainter painterLine(&image);
        painterLine.begin(&image);
        QPolygon pol;

        for (int j = 0; j < coordinatesX[i].size(); j++)
        {
            pol << QPoint(coordinatesX[i][j], coordinatesY[i][j]);
        }

        QPen pen;
        pen.setColor(color);
        pen.setStyle(Qt::SolidLine);
        pen.setWidth(thickness);
        painterLine.setPen(pen);

        painterLine.drawPolyline(pol);

        painterLine.end();

        pixMap = QPixmap::fromImage(image);
        imageLabel->setPixmap(pixMap);
    }
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton && doPaint)
    {
        currentPolygon++;
        paint = true;
        coordinatesX.push_back(QList<int>());
        coordinatesY.push_back(QList<int>());

        coordinatesX[currentPolygon].push_back(e->localPos().x());
        coordinatesY[currentPolygon].push_back(e->localPos().y()-25);

        dot = true;
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton && doPaint)
    {
        if (dot)
        {
            coordinatesX[currentPolygon].push_back(e->localPos().x() + 1);
            coordinatesY[currentPolygon].push_back(e->localPos().y()-25);
            update();
        }
        paint = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    if (!doPaint) return;
    coordinatesX[currentPolygon].push_back(e->localPos().x());
    coordinatesY[currentPolygon].push_back(e->localPos().y()-25);
    update();
    dot = false;
}

void MainWindow::openImageClick()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "D:/", tr("Image Files (*.png *.jpg *.bmp *.gif)"));
    pixMap = QPixmap(fileName);
    imageLabel->setPixmap(pixMap);

    saveImageAction->setEnabled(true);
    mirrorImageAction->setEnabled(true);
    chooseColorAction->setEnabled(true);
    chooseThicknessAction->setEnabled(true);
}

void MainWindow::saveImageClick()
{
    QString dir = QFileDialog::getSaveFileName(this, tr("Open Directory"), "D:/");
    pixMap.toImage().save(dir);
    QMessageBox::about(this, "", "Image Saved");
}

void MainWindow::mirrorImageClick()
{
    pixMap = QPixmap::fromImage(pixMap.toImage().mirrored(true, true));
    imageLabel->setPixmap(pixMap);
}

void MainWindow::chooseColorClick()
{
    color = QColorDialog::getColor();
}

void MainWindow::chooseThicknessClick()
{
    thickness = QInputDialog::getInt(this, "Thickness", "Enter thickness");
}

void MainWindow::createActions()
{
    openImageAction = new QAction(QIcon(":/icons/resources/open.png"), tr("&Open"),this);
    openImageAction->setShortcut(tr("Ctrl+O"));
    openImageAction->setToolTip(tr("Open Image"));
    openImageAction->setStatusTip(tr("Open Image"));
    connect(openImageAction, &QAction::triggered, this, &MainWindow::openImageClick);

    saveImageAction = new QAction(QIcon(":/icons/resources/save.png"), tr("&Save"),this);
    saveImageAction->setShortcut(tr("Ctrl+S"));
    saveImageAction->setToolTip(tr("Save Image"));
    saveImageAction->setStatusTip(tr("Save Image"));
    connect(saveImageAction, &QAction::triggered, this, &MainWindow::saveImageClick);

    mirrorImageAction = new QAction(QIcon(":/icons/resources/mirror.png"), tr("&Mirror"),this);
    mirrorImageAction->setShortcut(tr("Ctrl+M"));
    mirrorImageAction->setToolTip(tr("Mirror Image"));
    mirrorImageAction->setStatusTip(tr("Mirror Image"));
    connect(mirrorImageAction, &QAction::triggered, this, &MainWindow::mirrorImageClick);

    chooseColorAction = new QAction(QIcon(":/icons/resources/color.png"), tr("&Color"),this);
    chooseColorAction->setShortcut(tr("Ctrl+J"));
    chooseColorAction->setToolTip(tr("Choose Color"));
    chooseColorAction->setStatusTip(tr("Choose color"));
    connect(chooseColorAction, &QAction::triggered, this, &MainWindow::chooseColorClick);

    chooseThicknessAction = new QAction(QIcon(":/icons/resources/thickness.png"), tr("&Thickness"),this);
    chooseThicknessAction->setShortcut(tr("Ctrl+T"));
    chooseThicknessAction->setToolTip(tr("Choose Thickness"));
    chooseThicknessAction->setStatusTip(tr("Choose Thickness"));
    connect(chooseThicknessAction, &QAction::triggered, this, &MainWindow::chooseThicknessClick);



    saveImageAction->setEnabled(false);
    mirrorImageAction->setEnabled(false);
    chooseColorAction->setEnabled(false);
    chooseThicknessAction->setEnabled(false);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openImageAction);
    fileMenu->addAction(mirrorImageAction);
    fileMenu->addAction(chooseColorAction);
    fileMenu->addAction(chooseThicknessAction);
    fileMenu->addAction(saveImageAction);
}

void MainWindow::createToolBar()
{
    fileToolBar = addToolBar("filToolBar");
    fileToolBar->addAction(openImageAction);
    fileToolBar->addAction(mirrorImageAction);
    fileToolBar->addAction(chooseColorAction);
    fileToolBar->addAction(chooseThicknessAction);
    fileToolBar->addAction(saveImageAction);
}
