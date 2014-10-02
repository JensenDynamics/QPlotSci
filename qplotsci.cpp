/*
################LICENSE INFORMATION####################################
##########Copyright Elijah Jensen 2014 #####################################
Permission is given to any user for any purpose
with the clause that this software is "owned" by Elijah Jensen
You may include this software in any licensed software, however you may not
claim any patent or right to this software for ownership.
Furthermore:

The MIT License (MIT)

Copyright (c) 2014 Elijah Jensen / Jensen Dynamics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
############################################################################
*/

/* Help for this lib
 *
 *    You must define the following items in your program:   QGraphicsView *viewname; and QGraphicsScene
 *     QPlotSci will take care of the rest...... if you are using QTCreator then the QGraphics view is ui.graphicsView
 *     and the scene must be created in the header file for YOUR program, then linked view setupPlot(view,&scene);
 *
 *
 */


#include "qplotsci.h"
#include <QGraphicsView>
QPlotSci::QPlotSci()
{

}

void QPlotSci::setupPlot(QGraphicsView *view,QGraphicsScene *scene)
{

view->setScene(scene);
view->show();
theScene = scene;
theView = view;

//theView->scale(1.5,1.5);
}

void QPlotSci::plotLines(double *x, double *y,int N)
{

    theScene->clear();
    theScene->clearFocus();
    theScene->clearSelection();

    int i =0;
    QPen pen;

    pen.setColor(Qt::blue);
    pen.setWidth(2.5);
    pen.setCosmetic(true);
    pen.setStyle(Qt::SolidLine);
    pen.setJoinStyle(Qt::RoundJoin);

    int size = 800;





    QPen gridpen;
    gridpen.setColor(Qt::gray);
    gridpen.setWidth(0.5);

    int yextent = size;
    int xextent = size;
    int gridspacing =50;


    for(int i =-xextent; i<=xextent; i=i+gridspacing){
   // scene.addLine(0,-1*yextent,0,yextent,gridpen);
    theScene->addLine(i,-1*yextent,i,yextent,gridpen);
    }
    for(int j=-1*yextent; j<=yextent; j=j+gridspacing)
    {

      //  scene.addLine(0,0,0,100,gridpen);
        theScene->addLine(-1*xextent,j,xextent,j,gridpen);


}

    theView->scale(2,2);





   theScene->setSceneRect(0,0,20,20);

    for(i=0; i<N-1; i++)
    {
    theScene->addLine(x[i],-y[i],x[i+1],-y[i+1],pen);
    }


   theView->scale(1,1);
  //  Qt::AspectRatioMode aspect = Qt::IgnoreAspectRatio;
   // theView->fitInView(0,0,20,20,Qt::IgnoreAspectRatio);
    theView->setAlignment(Qt::AlignLeft);


    theView->update();

}


void QPlotSci::plotLines(double *x, double *y,int N, QPen pen1)
{
    int i =0;
    for(i=0; i<N-1; i++)
    {
   theScene->addLine(x[i],-y[i],x[i+1],-y[i+1],pen1);
    }
}
