#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QToolButton>
#include <QWidgetAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    auto toolbar = ui->toolBar;

    auto separator = new QWidget(this);
    separator->setFixedSize(2, 24); // # 2 pixels wide, 24 pixels tall
    separator->setStyleSheet("background-color: darkgray;");



    auto bookAction = findActionByName(toolbar, "actionBook");
    toolbar->insertWidget(bookAction, separator);

    if (bookAction) {
        bookMenu = new QMenu(this);
        auto actionA = new QAction("Open", this);
        auto actionB = new QAction("Save", this);
        bookMenu->addAction(actionA);
        bookMenu->addAction(actionB);

        // bookAction->setMenu(bookMenu);
        // bookMenu->show();
        // QToolButton* button = qobject_cast<QToolButton*>(toolbar->widgetForAction(bookAction));

        // if (button) {
            // Change the popup behavior
            // button->setPopupMode(QToolButton::InstantPopup);
        // }
        connect(bookAction, &QAction::triggered, this, &MainWindow::toolbarActionClick);
    }

    // Set a context menu policy for the widget
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

QAction* MainWindow::findActionByName(QToolBar* toolbar, const QString& name)
{
    const QList<QAction*>& actions = toolbar->actions();
    for (QAction* action : actions) {
        if (action->objectName() == name) {
            return action;
        }
    }
    return nullptr; // Action not found
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{

    qDebug() << "context menu event " << "\n";
}

void MainWindow::toolbarActionClick()
{
    qDebug() << "action click" << "\n";

    QObject* who = sender();

    QAction* action = dynamic_cast<QAction *>(who);


    QToolButton* toolButton = dynamic_cast<QToolButton *>(ui->toolBar->widgetForAction(action));
    if (toolButton) {
        auto rec = toolButton->rect();
        auto pos = toolButton->mapToGlobal(QPoint(rec.left(), rec.bottom()));

        bookMenu->popup(pos);

    }


    // QMenu menu(this);

    // Add actions to the menu
    // QAction* openAction = menu.addAction("Open");
    // QAction* saveAction = menu.addAction("Save");
    // menu.addSeparator(); // Add a separator line
    // QAction* exitAction = menu.addAction("Exit");

    // Execute the menu at the cursor's position
    // QAction* selectedAction = menu.exec(action->gi);

    // Get the global position to show the menu at (e.g., the center of the widget)
    // QPoint globalPos = action->mapToGlobal(action->rect().center());

    // Create a new context menu event
    // QContextMenuEvent* event = new QContextMenuEvent(QContextMenuEvent::Other,
                                                     // widget->rect().center(),
                                                     // globalPos);

    // Send the event to the widget
    // QCoreApplication::postEvent(widget, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
