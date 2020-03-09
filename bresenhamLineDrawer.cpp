void bresenhamLineDrawer(int x1,int x2, int y1, int y2,int z1,int z2, unsigned int color1, unsigned int color2)
{
    // Draws line from pt1 to pt2 into the z buffer using clipping



    int x,y,dx,dy,dx1,dy1,Erorx,Erory,xe,ye,t2,t1,i,two_dy,two_dx;
     dx=x2-x1; //change in x
     dy=y2-y1; //change in y
     dx1=fabs(dx); //absolute change in x, use in any octant for t2 and error
     dy1=fabs(dy); //absolute change in y, use in any octant for t2 and error
     two_dy=2*dy1; // two dy
     two_dx=2*dx1; // two dx
     Erorx=two_dy-dx1; //the error for octant 1,4,5,8
     Erory=two_dx-dy1; //the error for octant 2,3,6,7
     t1=two_dy-two_dx; // the value you add to error when increase x,y by 1
     t2=two_dx-two_dy; // the value you add to error when increase x,y by 1
     int r1,r2,g1,g2,b1,b2;
     colorToRBG(color1,r1,g1,b1);
     colorToRBG(color2,r2,g2,b2);
     if(dy1<=dx1) //if dx>dy octant 1,4,5,8
     {
         int redcolor[dx1];
         int greencolor[dx1];
         int bluecolor[dx1];
         int Zdist[dx1];
          if(dx>=0) //if drawing in octant 1 or 8
          {
               x=x1; //leave everything the same
               y=y1;
               xe=x2;
               colorDDA(x,xe,redcolor,r1,r2);
               colorDDA(x,xe,greencolor,g1,g2);
               colorDDA(x,xe,bluecolor,b1,b2);
               Zdepth(z1,z2,Zdist,x,xe);
          }
          else //if drawing in octant 4 or 5
          {
               x=x2; //switch x and y, so your still going from left to right
               y=y2;
               xe=x1;
               colorDDA(x,xe,redcolor,r2,r1);
               colorDDA(x,xe,greencolor,g2,g1);
               colorDDA(x,xe,bluecolor,b2,b1);
               Zdepth(z2,z1,Zdist,x,xe);
          }

          int k=0;
          int long curColor;
              curColor=RBGToint(redcolor[0],greencolor[0],bluecolor[0]);

              if(clipp(x,y))
              {
                    if(zcheck(x,y,Zdist[0]))
                    {
                        int tempx,tempy;
                        tempx=x-50;
                        tempy=y-50;
                        Z_buffer[tempx][tempy]=Zdist[0];
                        Color_buffer[tempx][tempy]=curColor;
                    //drawable->setPixel(x,y,curColor); //let the first pixe;
                    }
              }
          for(i=0;x<xe;i++) //loop
           {
           x=x+1; //increase x ever round
           if(Erorx>=0) //if error large enough we can now increase y
           {
               if((dx<0 && dy<0) || (dx>0 && dy>0)) //if in octant 1
               {
                   y=y+1;
               }
               else //if in octant 8
               {
                   y=y-1;
               }
               Erorx=Erorx+t1;

           }
           else
           {
                Erorx=Erorx+two_dy;
           }

                curColor=RBGToint(redcolor[k],greencolor[k],bluecolor[k]);

                if(clipp(x,y))
                {
                    if(zcheck(x,y,Zdist[k]))
                    {
                        int tempx,tempy;
                        tempx=x-50;
                        tempy=y-50;
                        Z_buffer[tempx][tempy]=Zdist[k];
                        Color_buffer[tempx][tempy]=curColor;
                        //drawable->setPixel(x,y,curColor);
                    }
                }
                k=k+1;

      }
     }
     else //same as before but for octant 2,3,6,7
     {
         int redcolor[dy1];
         int greencolor[dy1];
         int bluecolor[dy1];
         int Zdist[dy1];
          if(dy>=0) //the same basically switching x and y.
          {
               x=x1;
               y=y1;
               ye=y2;
               colorDDA(y,ye,redcolor,r1,r2);
               colorDDA(y,ye,greencolor,g1,g2);
               colorDDA(y,ye,bluecolor,b1,b2);
               Zdepth(z1,z2,Zdist,y,ye);
          }
          else
          {
               x=x2;
               y=y2;
               ye=y1;

               colorDDA(y,ye,redcolor,r2,r1);
               colorDDA(y,ye,greencolor,g2,g1);
               colorDDA(y,ye,bluecolor,b2,b1);
               Zdepth(z2,z1,Zdist,y,ye);
          }
          int k=0;
          int long curColor;
              curColor=RBGToint(redcolor[0],greencolor[0],bluecolor[0]);

              if(clipp(x,y))
              {
                  if(zcheck(x,y,Zdist[0]))
                  {
                      int tempx,tempy;
                      tempx=x-50;
                      tempy=y-50;
                      Z_buffer[tempx][tempy]=Zdist[0];
                      Color_buffer[tempx][tempy]=curColor;
                    //drawable->setPixel(x,y,curColor);
                  }
               }
          for(i=0;y<ye;i++)
          {
               y=y+1;
               if(Erory>=0)
               {
                   if((dx<0 && dy<0) || (dx>0 && dy>0))
                   {
                       x=x+1;
                   }
                   else
                   {
                        x=x-1;
                   }
               Erory=Erory+t2;

               }
               else
               {
                   Erory=Erory+two_dx;
               }

                   curColor=RBGToint(redcolor[k],greencolor[k],bluecolor[k]);

                   if(clipp(x,y))
                   {
                       if(zcheck(x,y,Zdist[k]))
                       {
                           int tempx,tempy;
                           tempx=x-50;
                           tempy=y-50;
                           Z_buffer[tempx][tempy]=Zdist[k];
                           Color_buffer[tempx][tempy]=curColor;
                        //drawable->setPixel(x,y,curColor);
                       }
                   }
                   k=k+1;

          }
     }

}
