#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "yuan.h"
#include "newnode.h"
#include "widgetmap.h"
#include "logic_help.h"

typedef Rec Logic;

//class DiagramWindow;
/********************************************************************
* Class name: newscene
* Description: provide a new scene to do some mouse-events
********************************************************************/
class newscene:public QGraphicsScene
{
    Q_OBJECT
public:
    newscene(WidgetMap* m, QMap<QString,LOGIC_Help*>*L);
    ~newscene();
    specialYuan* new_yuan;

    void bringToFront();


    bool CreateWidgets();
    //从用户鼠标事件创建控件
    bool CreateTakeOff(QPointF point, int id);
    bool CreateLand(QPointF point, int id);
    bool CreateGo(QPointF point, int id, int index);
    bool CreateTurn(QPointF point, int id, int index);
    bool CreateHover(QPointF point, int id);
    bool CreateDelay(QPointF point, int id);
    bool CreateVar(QPointF point, int id);
//    bool CreateVarInstance(QPointF point, int id);
    bool CreateCompute(QPointF point, int id,int selected_Index);
    bool CreateSin(QPointF point, int id);
    bool CreateLog(QPointF point, int id);
    bool CreateE(QPointF point, int id);
    bool CreateTriCompute(QPointF point, int id);
    bool CreateIO(QPointF point, int id);
    bool CreateBattery(QPointF point, int id);
    bool CreateGimbal(QPointF point, int id);
    bool CreateAttitude(QPointF point, int id);
    bool CreateChannel(QPointF point, int id);
    bool CreateRangeFinder(QPointF point, int id);
    bool CreateLogic(QPointF point, int id);
    bool CreateIf(QPointF point, int id);
    bool CreateWhile(QPointF point, int id);
    bool CreateElse(QPointF point, int id);//其实这三个createlogic可以合成一个函数，函数变量多一个参数而已
    Link* CreateLink(QGraphicsSceneMouseEvent* event);

    //从xml文件创建控件
    bool CreateTakeOff(TakeOffNode* ton);
    bool CreateLand(LandNode* ln);
    bool CreateGo(GoNode* gn);
    bool CreateTurn(TurnNode* tn);
    bool CreateHover(HoverNode* hn);
    bool CreateDelay(DelayNode* dn);
    bool CreateVar(VarNode* vtn);
    bool CreateVarInstance(VarInstanceNode* vdn);
    bool CreateCompute(ComputeNode* cn);
    bool CreateE(eNode* cn);
    bool CreateLog(logNode* cn);
    bool CreateSin(sinNode* cn);
    bool CreateIO(IoNode* ion);
    bool CreateBattery(BatteryNode* ion);
    bool CreateGimbal(GimbalNode* ion);
    bool CreateAttitude(AttitudeNode* ion);
    bool CreateChannel(ChannelNode* ion);
    bool CreateRangeFinder(RangeFinderNode* ion);
    bool CreateLogic(Rec* ln);
    bool CreateIf(Rec* ifNode);
    bool CreateWhile(Rec* whileNode);
    bool CreateElse(Rec* elseNode);//其实这三个createlogic也可以合成一个函数
    bool CreateLink(Link* link);

    bool CheckInLogic();    //调用方法
    Rec *check_in_Logic(WidgetWrap *tmp, QString operate, int maxrank);  //调用方法的内部工具
    bool CheckLinkOverLogic(Link* link);
    void del();

    int need_to_set;
    int selected_Index;

    int VarNodeNum;  //计数varNode,命名每个varNode,下同
    int VarInstanceNodeNum;

    int LogicNodeNum;

    int takeoffNodeNum;
    int landonNodeNum;
    int GoNodeNum;  //6个方向的直线运动控件都包含在内
    int TurnNodeNum;    //左右两个方向的转向控件
    int HoverNodeNum;
    int DelayNodeNum;

    int ComputeNodeNum;

    int IONodeNum;
    int BatteryNodeNum;
    int GimbalNodeNum;
    int AttitudeNodeNum;
    int ChannelNodeNum;
    int RangeFinderNodeNum;

    int linkNodeNum;

    WidgetMap* wm;
    QMap<QString,LOGIC_Help*>* LHM;

signals:
    void itemInserted(int index);
    void sig_bringtofront();
    void sig_connectItem(QObject *item);
    void sig_link_deleted(QSet<Link *> links);

public slots:
    void CreateVarInstance(VarNode *node,QString Var,QString varName,QString varValue);//点击variable每一行末端的按钮，就会调用此槽函数，在场景中生成对应变量


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* new_event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // SCENE_H
