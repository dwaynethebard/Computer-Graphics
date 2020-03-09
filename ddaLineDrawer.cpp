void ddaLineDrawer(int x1,int x2, int y1, int y2, unsigned int color)
{
    float m; //slope
    float b=0; //y intercept
    float X=x2-x1; //dx change in x
    float Y=y2-y1;//dy change in y
    m=Y/X;
    float x;
    float y;
    int dx,dy,dx1,dy1,xe,ye;
     dx=x2-x1; //dx
     dy=y2-y1; //dy
     dx1=fabs(dx);//absolute value of dx
     dy1=fabs(dy);//absolute value of dy

     if(dy1<=dx1) //if dx>dy octant 1,4,5,8
     {
          if(dx>=0) //oct 1,8
          {
               x=x1;
               y=y1;
               xe=x2;
          }
          else //oct 4,5
          {
               x=x2;
               y=y2;
               xe=x1;

          }
          b=y1-m*x1;

          for(;x<=xe;x++)
           {
                y=m*x+b;
                drawable->setPixel(x,round(y),color);
            }
     }
     else if(dy1>dx1) //octant 2,3,6,7
     {
          if(dy>=0) //oct 2,3
          {
               x=x1;
               y=y1;
               ye=y2;
          }
          else //oct 6,7
          {
               x=x2;
               y=y2;
               ye=y1;
          }
          X=x2-x1;
          Y=y2-y1;
          m=X/Y;
          b=x1-m*y1;
          for(; y<=ye;y=y+1)
          {
              x=m*y+b;
              drawable->setPixel(round(x),y,color);

          }

        }

}
