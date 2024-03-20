#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(QSize(1200, 900));
    oglwidget = new OGLWidget(this);
    QSlider* psid = new QSlider(Qt::Horizontal);
    psid->setRange(1,30);
    psid->setPageStep(1);
    psid->setValue(2);
    psid->setTickInterval(1);
    psid->setTickPosition(QSlider::TicksBelow);
    connect(psid, SIGNAL(valueChanged(int)), oglwidget, SLOT(slotChangeSize(int)));
    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->setDirection(QBoxLayout::TopToBottom);
    pvbxLayout->addWidget(new QLabel("Size"));
    pvbxLayout->addWidget(psid);

    QComboBox* cbo = new QComboBox();
    QStringList lst;
    lst << "GL_POINTS" << "GL_LINES" << "GL_LINE_LOOP" <<
        "GL_LINE_STRIP" << "GL_TRIANGLES" << "GL_TRIANGLES_STRIP"
        << "GL_TRIANGLE_FAN" << "GL_QUADS" << "GL_QUAD_STRIP" <<
           "GL_POLYGON";
    cbo->addItems(lst);
    pvbxLayout->addWidget(cbo);
    connect(cbo, SIGNAL(currentIndexChanged(int)), oglwidget, SLOT(slotChangeType(int)));

    QPushButton* pcmd = new QPushButton("Color");
    pvbxLayout->addWidget(pcmd);
    connect(pcmd, &QPushButton::clicked, [=](){oglwidget->slotChangeColor(QColorDialog::getColor(Qt::blue, this, QString("test"), QColorDialog::DontUseNativeDialog | QColorDialog::ShowAlphaChannel));});

    QSlider* psidSCx = new QSlider(Qt::Horizontal);
    psidSCx->setRange(0, oglwidget->width());
    psidSCx->setPageStep(1);
    psidSCx->setTickInterval(1);
    connect(psidSCx, SIGNAL(valueChanged(int)), oglwidget, SLOT(slotChangeSCx(int)));
    pvbxLayout->addWidget(new QLabel("Scissors_x"));
    pvbxLayout->addWidget(psidSCx);
    QSlider* psidSCy = new QSlider(Qt::Horizontal);
    psidSCy->setRange(0, oglwidget->height());
    psidSCy->setPageStep(1);
    psidSCy->setTickInterval(1);
    connect(psidSCy, SIGNAL(valueChanged(int)), oglwidget, SLOT(slotChangeSCy(int)));
    pvbxLayout->addWidget(new QLabel("Scissors_y"));
    pvbxLayout->addWidget(psidSCy);
    QSlider* psidSCw = new QSlider(Qt::Horizontal);
    psidSCw->setRange(0, oglwidget->width());
    psidSCw->setPageStep(1);
    psidSCw->setTickInterval(1);
    connect(psidSCw, SIGNAL(valueChanged(int)), oglwidget, SLOT(slotChangeSCw(int)));
    pvbxLayout->addWidget(new QLabel("Scissors_w"));
    pvbxLayout->addWidget(psidSCw);
    QSlider* psidSCh = new QSlider(Qt::Horizontal);
    psidSCh->setRange(0, oglwidget->height());
    psidSCh->setPageStep(1);
    psidSCh->setTickInterval(1);
    connect(psidSCh, SIGNAL(valueChanged(int)), oglwidget, SLOT(slotChangeSCh(int)));
    pvbxLayout->addWidget(new QLabel("Scissors_h"));
    pvbxLayout->addWidget(psidSCh);

    pvbxLayout->addWidget(new QLabel("Alpha test function"));
    QComboBox* cboA = new QComboBox();
    lst.clear();
    lst << "GL_NEVER " << "GL_LESS" << "GL_EQUAL" <<
        "GL_LEQUAL" << "GL_GREATER" << "GL_NOTEQUAL"
        << "GL_GEQUAL" << "GL_ALWAYS" ;
    cboA->addItems(lst);
    cboA->setCurrentIndex(7);
    pvbxLayout->addWidget(cboA);
    QSlider* psidA= new QSlider(Qt::Horizontal);
    psidA->setRange(0, 10);
    psidA->setPageStep(1);
    psidA->setTickInterval(1);
    pvbxLayout->addWidget(new QLabel("Alpha test ref value"));
    pvbxLayout->addWidget(psidA);
    connect(cboA, SIGNAL(currentIndexChanged(int)), oglwidget, SLOT(slotChangeTransperencyType(int)));
    connect(psidA, SIGNAL(valueChanged(int)), oglwidget, SLOT(slotChangeTransperencyRef(int)));

    pvbxLayout->addWidget(new QLabel("sfactor"));
    QComboBox* cboB = new QComboBox();
    lst.clear();
    lst << "GL_ZERO" << "GL_ONE"
        << "GL_SRC_ALPHA" << "GL_ONE_MINUS_SRC_ALPHA"
        << "GL_DST_ALPHA" << "GL_ONE_MINUS_DST_ALPHA"
        << "GL_DST_COLOR" <<"GL_ONE_MINUS_DST_COLOR"
        << "GL_SRC_ALPHA_SATURATE" ;
    cboB->addItems(lst);
    cboB->setCurrentIndex(1);
    pvbxLayout->addWidget(cboB);
    pvbxLayout->addWidget(new QLabel("dfactor"));
    QComboBox* cboB2 = new QComboBox();
    lst.clear();
    lst << "GL_ZERO" << "GL_ONE" << "GL_SRC_COLOR" <<
        "GL_ONE_MINUS_SRC_COLOR" << "GL_SRC_ALPHA" << "GL_ONE_MINUS_SRC_ALPHA"
        << "GL_DST_ALPHA" << "GL_ONE_MINUS_DST_ALPHA " ;
    cboB2->addItems(lst);
    pvbxLayout->addWidget(cboB2);

    connect(cboB, SIGNAL(currentIndexChanged(int)), oglwidget, SLOT(slotChangeBlendS(int)));
    connect(cboB2, SIGNAL(currentIndexChanged(int)), oglwidget, SLOT(slotChangeBlendD(int)));

    pbxLayout->addWidget(oglwidget,5);
    pbxLayout->addLayout(pvbxLayout,1);


    setLayout(pbxLayout);

    connect(oglwidget, &OGLWidget::resized, [=](){psidSCh->setRange(0, oglwidget->height());psidSCh->setValue(oglwidget->height()); psidSCw->setRange(0, oglwidget->width());psidSCw->setValue(oglwidget->width())
    ;psidSCx->setRange(0, oglwidget->width());psidSCy->setRange(0, oglwidget->height());});

}




