#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QMouseEvent>
#include <QPoint>
#include <QtMath>




struct VertexData
{
    VertexData() {}
    VertexData(QVector3D p, QVector2D t, QVector3D n)
        : position(p)
        , textCoord(t)
        , normal(n)
    {}

    QVector3D position;
    QVector2D textCoord;
    QVector3D normal;
};
class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void initShaders();
    void drawCube(float width);

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);

private:
    QMatrix4x4 projectionMatrix;
    QOpenGLShaderProgram program;
    QOpenGLTexture *texture;
    QOpenGLBuffer arrayBuffer;
    QOpenGLBuffer indexBuffer;
    QVector2D mousePosition;
    float xRot, yRot;



};
#endif // WIDGET_H
