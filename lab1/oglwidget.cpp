#include "oglwidget.h"

OGLWidget::OGLWidget(QWidget* pwgt): QOpenGLWidget(pwgt){

}

void OGLWidget::initializeGL(){
    QOpenGLFunctions* pFunc = QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void OGLWidget::resizeGL(int nWidth, int nHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,(GLint)nWidth, (GLint)nHeight);
    glOrtho(0, nWidth, nHeight, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OGLWidget::paintGL(){
   // QRandomGenerator *rg = QRandomGenerator::global();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_SCISSOR_TEST);
    glScissor(SC_x,SC_y,SC_w,SC_h);
    glAlphaFunc(this->tr_type, this->tr_ref);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(this->bl_s, this->bl_d);
    glPointSize(this->size);
    glLineWidth(this->size);
    glBegin(this->type);
    for(int i = 0; i < points.size(); i++){
       // glColor4ub(rg->bounded(0,255),rg->bounded(0,255),rg->bounded(0,255), rg->bounded(0,255)); //весёлый режим цвета
        glColor4ub(points[i].r,points[i].g,points[i].b, points[i].a);
        glVertex2f(points[i].x, points[i].y);
    }
    glEnd();
    this->update();
}



void OGLWidget::mousePressEvent(QMouseEvent *pe)
{
    if(pe->buttons() & Qt::LeftButton)
        this->points.append(point{pe->position().x(),pe->position().y(),curr_color.red(),curr_color.green(),curr_color.blue(), curr_color.alpha()});
    if(pe->buttons() & Qt::RightButton && !this->points.isEmpty())
        this->points.pop_back();
}

void OGLWidget::slotChangeSize(int size){
    this->size = size;
}

void OGLWidget::slotChangeType(int type){
    this->type = (GLenum)type;
}

void OGLWidget::slotChangeColor(QColor color){
    if(color.isValid())
        this->curr_color = color;
}

void OGLWidget::slotChangeSCx(int x){
    this->SC_x = x;
}

void OGLWidget::slotChangeSCy(int y){
    this->SC_y = y;
}

void OGLWidget::slotChangeSCw(int w){
    this->SC_w = w;
}

void OGLWidget::slotChangeSCh(int h){
    this->SC_h = h;
}

void OGLWidget::slotChangeTransperencyRef(int ref){
    this->tr_ref = ((float)ref)/10;
}

void OGLWidget::slotChangeTransperencyType(int type){
    this->tr_type = (GLenum)(type + 512);
}

void OGLWidget::slotChangeBlendS(int type){
    if (type == 0 || type == 1)
        this->bl_s = (GLenum)type;
    else
        this->bl_s = (GLenum)(type + 768);
}
void OGLWidget::slotChangeBlendD(int type){
    if (type == 0 || type == 1)
        this->bl_d = (GLenum)type;
    else
        this->bl_d = (GLenum)(type + 766);
}

