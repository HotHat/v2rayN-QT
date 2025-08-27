#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //
    QAction* findActionByName(QToolBar* toolbar, const QString& name);

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void toolbarActionClick();

private:
    Ui::MainWindow *ui;
    QMenu *bookMenu;
};
#endif // MAINWINDOW_H
