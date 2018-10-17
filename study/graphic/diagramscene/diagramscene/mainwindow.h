#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "diagramitem.h"
#include "diagramscene.h"

QT_BEGIN_NAMESPACE

class QAction;
class QMenu;
class QToolBar;
class QToolBox;
class QSpinBox;
class QComboBox;
class QFontComboBox;
class QButtonGroup;
class QLineEdit;
class QGraphicsTextItem;
class QFont;
class QAbstractButton;
class QGraphicsView;
class QToolButton;
class QGraphicsItem;

QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    ~MainWindow();

private slots:
    void backgroundButtonGroupClicked(QAbstractButton *button);
    void buttonGroupClicked(int id);
    void delteItem();
    void pointerTypeGroupClicked(int id);
    void bringToFront();
    void sendToBack();

    void itemInserted(DiagramItem *item);
    void textInserted(QGraphicsTextItem *item);

    void currentFontChanged(const QFont &font);
    void fontSizeChanged(const QString &size);

    void sceneScaleChanged(const QString &size);

    void textColorChanged();
    void itemColorChanged();
    void lineColorChanged();

    void textButtonTriggered();
    void fillButtonTriggered();
    void lineButtonTriggered();
    void handleFontChange();
    void itemSelected(QGraphicsItem *item);

    void about();

private:

    void createToolBox();
    void createActions();
    void createMenus();
    void createToolBars();

    QWidget *createBackgroundCellWidget(const QString &text,
                                        const QString &image);
    QWidget *createCellWidget(const QString &text,
                              DiagramItem::DiagramType type
                              );


    QMenu *createColorMenu(const char* slot, QColor defaultColor);
    QIcon createColorToolButtonIcon(const QString &image, QColor color);
    QIcon createColorIcon(QColor color);

    QAction *exitAction;
    QAction *addAction;
    QAction *delteAction;

    QAction *toFrontAction;
    QAction *sendBackAction;
    QAction *aboutAction;

    QMenu *fileMenu;
    QMenu *itemMenu;
    QMenu *helpMenu;

    QToolBar *textToolBar;
    QToolBar *editToolBar;
    QToolBar *colorToolBar;
    QToolBar *pointerToolBar;

    QComboBox *sceneScaleCombo;
    QComboBox *itemColorCombo;
    QComboBox *textColorCombo;
    QComboBox *fontSizeCombo;
    QFontComboBox *fontCombo;

    QToolBox *toolBox;
    QButtonGroup *buttonGroup;
    QButtonGroup *pointerTypeGroup;
    QButtonGroup *backgroundButtonGroup;
    QToolButton *fontColorToolButton;
    QToolButton *fillColorToolButton;
    QToolButton *lineColorToolButton;

    QAction *boldAction;
    QAction *underlineAction;
    QAction *italicAciton;
    QAction *textAction;
    QAction *fillAction;
    QAction *lineAction;

    DiagramScene *scene;
    QGraphicsView *view;


    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
