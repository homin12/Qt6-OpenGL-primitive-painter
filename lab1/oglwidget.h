#ifndef OGLWidget_H
#define OGLWidget_H
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QPair>
#include <QVector>
#include <QRandomGenerator>
#include <QColor>
struct point{
    int x,y,r,g,b,a;
};

class OGLWidget : public QOpenGLWidget
{
    Q_OBJECT
private:
    int size = 2;
    GLenum type = GL_POINTS;
    QVector<point> points;
    QColor curr_color = QColor{0,0,0,255};
    int SC_x = 0;
    int SC_y = 0;
    int SC_w = this->width();
    int SC_h = this->height();
    GLenum tr_type = GL_ALWAYS;
    GLenum bl_s = GL_ONE;
    GLenum bl_d = GL_ZERO;
    float tr_ref = 0;
    virtual void initializeGL();
    virtual void resizeGL(int nWidth, int nHeight);
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent* pe);

public:
    OGLWidget(QWidget* pwgt = 0);
public slots:
    void slotChangeSize(int);
    void slotChangeType(int);
    void slotChangeColor(QColor);
    void slotChangeSCx(int);
    void slotChangeSCy(int);
    void slotChangeSCw(int);
    void slotChangeSCh(int);
    void slotChangeTransperencyType(int);
    void slotChangeTransperencyRef(int);
    void slotChangeBlendS(int);
    void slotChangeBlendD(int);
};

#endif // OGLWidget_H
