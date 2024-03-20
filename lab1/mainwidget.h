#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "oglwidget.h"
#include <QSlider>
#include <QColorDialog>
#include <QComboBox>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
class MainWidget : public QWidget
{
    Q_OBJECT
private:
    OGLWidget* oglwidget;
public:
    explicit MainWidget(QWidget *parent = nullptr);

signals:

};

#endif // MAINWIDGET_H
