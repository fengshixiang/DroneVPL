#ifndef COMPUTENODE_H
#define COMPUTENODE_H


#include "QObject"
#include <QtGui>
#include "node.h"
#include "itemtypes.h"

class Yuan;
class QComboBox;
class QGraphicsItem;
class ComputeSmallNode;
/*******************************************************************
 * Class name: ComputeNode
 * Base class: Node
 * Description: This is the declaration of class ComputeNode.
 *       ComputeNode is a node which connect two varnodes (variables)
 *       and compute an outcome.
******************************************************************/
class ComputeNode:public Node
{
    Q_OBJECT
public:
    enum {Type = ComputeNodeType};
    ComputeNode();
    ~ComputeNode();

    int type() const { return Type; }

    QRectF outlineRect() const;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    Yuan* yuan2;
    triYuan* yuan3;
    QComboBox* box;
    QGraphicsItem* item;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QGraphicsItem *lineItem1,*lineItem2;

    /*ComputeSmallNode *rect1;
    QString rect1text;
    ComputeSmallNode *rect2;
    QString rect2text;*/

    static int ComputeNodeAddNum; static int ComputeNodeSubNum;
    static int ComputeNodeMulNum; static int ComputeNodeDivNum;
    static int ComputeNodeEqualNum;
    static int ComputeNodeMoreNum; static int ComputeNodeLessNum;

protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private slots:
    void setNewIdentifier();
};

/*class ComputeNode:public Node
{
    Q_OBJECT
public:
    enum {Type = ComputeNodeType};
    ComputeNode();
    ~ComputeNode();

    int type() const{return Type;}

    QRectF outlineRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Yuan *yuan2;
    Yuan *yuan3;

    static int ComputeNodeAddNum; static int ComputeNodeSubNum;
    static int ComputeNodeMulNum; static int ComputeNodeDivNum;
    static int ComputeNodeCosNum; static int ComputeNodeSinNum;
    static int ComputeNodeTanNum; static int ComputeNodeLogNum;
    static int ComputeNodeENum; static int ComputeNodeEqualNum;
    static int ComputeNodeMoreNum; static int ComputeNodeLessNum;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};*/

class  ComputeSmallNode:public Node
{
    Q_OBJECT
public:
    enum {Type = ComputeSmallNodeType};
    ComputeSmallNode();

    int type() const{return Type;}

    QRectF outlineRect()const;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

};

class sinNode:public Node
{
    Q_OBJECT
public:
    enum {Type = ComputeNodeType};
    sinNode();
    ~sinNode();

    int type() const { return Type; }

    QRectF outlineRect() const;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    Yuan* yuan2;
    triYuan* yuan3;
    QComboBox* box;
    QGraphicsItem* item;
    QLineEdit *lineEdit2;
    QGraphicsItem *lineItem2;

    /*ComputeSmallNode *rect1;
    QString rect1text;
    ComputeSmallNode *rect2;
    QString rect2text;*/

    static int ComputeNodeCosNum; static int ComputeNodeSinNum;
    static int ComputeNodeTanNum;

protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private slots:
    void setNewIdentifier();
};

class logNode:public Node
{
    Q_OBJECT
public:
    enum {Type = ComputeNodeType};
    logNode();
    ~logNode();

    int type() const { return Type; }

    QRectF outlineRect() const;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    Yuan* yuan2;
    triYuan* yuan3;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QGraphicsItem *lineItem1;
    QGraphicsItem *lineItem2;

    static int ComputeNodeLogNum;

protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

class eNode:public Node
{
    Q_OBJECT
public:
    enum {Type = ComputeNodeType};
    eNode();
    ~eNode();

    int type() const { return Type; }

    QRectF outlineRect() const;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

    Yuan* yuan2;
    triYuan* yuan3;
    QLineEdit *lineEdit2;
    QGraphicsItem *lineItem2;

    static int ComputeNodeENum;
protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};



#endif // COMPUTENODE_H
