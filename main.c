#include <stdio.h>
#include <stdlib.h>
#include "computerCourse.h"

int main(){
    int menu;
    int index=0,count=0;
    int cartIndex=0,cartCount=0;
    computerCourse c[100];
    computerCourse cart[20];

    //index = count = loadData(c);

    while(1){
        menu = selectMenu();
        if((menu==1||menu==3||menu==4)&&count==0) continue;

        if(menu==1){
            //ì¡°íšŒ
            if(count>0){ 
                //ë§Œì•½ ì§?ê¸? ë³´ìœ ?•˜ê³? ?ˆ?Š” ?°?´?„°ê°? ?ˆ?‹¤ë©?
                listCourse(c, index);
                //listë³´ì—¬ì£¼ê¸°
            } else{
                //ë§Œì•½ ì§?ê¸? ë³´ìœ ?•˜ê³? ?ˆ?Š” ?°?´?„°ê°? ?•˜?‚˜?„ ?—†?‹¤ë©??
                printf("?°?´?„°ê°? ?—†?Šµ?‹ˆ?‹¤!\n");
            }
        }
        else if(menu==2){
            //ì¶”ê??
              count += addCourse(&c[index]);
              index++;
              }
        
        else if(menu==3){
            //?ˆ˜? •
            int no = selectDataNum(c,index);
            if(no>0)
                updateCourse(&c[no-1]);
            else
                printf("ì·¨ì†Œ?˜?—ˆ?Šµ?‹ˆ?‹¤!n");
        }
        else if(menu==4){
            //?‚­? œ
            int delCourse = selectDataNum(c, index);
            int del = 0;
            printf("? •ë§ë¡œ ?‚­? œ?•˜?‹œê² ìŠµ?‹ˆê¹??(?‚­? œ:1)");
            scanf("%d", &del);
            if(del == 1){
                if(deleteCourse(&c[delCourse-1]) == 1){
                printf("?‚­? œ?¨!\n");
                count --;
                }
            }
        }

        /*
        else if(menu==5){
            //????¥
        }else if(menu==6){
            //?´ë¦„ìœ¼ë¡? ê²??ƒ‰
        }else if(menu==7){
            //?•™? ?œ¼ë¡? ê²??ƒ‰
        }*/
        else if(menu==8){
            int no = selectDataNum(c,index);
            cartCount += addInCart(&cart[cartIndex++],c[no-1]);
            //?¥ë°”êµ¬?‹ˆ?— ?‹´ê¸?
        }
        else if(menu==9){ 
            //?¥ë°”êµ¬?‹ˆ?— ?‹´??? ê³¼ëª© ë³´ì—¬ì£¼ê¸°
            if(cartCount>0){ 
                //ë§Œì•½ ì§?ê¸? ?¥ë°”êµ¬?‹ˆ?— ?ˆ?Š” ?°?´?„°ê°? ?ˆ?‹¤ë©?
                showchoose(cart, cartCount);
                //listë³´ì—¬ì£¼ê¸°
            } else{
                //ë§Œì•½ ì§?ê¸? ?¥ë°”êµ¬?‹ˆ?— ?ˆ?Š” ?°?´?„°ê°? ?•˜?‚˜?„ ?—†?‹¤ë©??
                printf("?¥ë°”êµ¬?‹ˆ?— ?‹´ê¸? ê³¼ëª©?´ ?—†?Šµ?‹ˆ?‹¤.\n");
            }
        
        }
        
        else if(menu==10){
            break;
        }
    }

    return 0;
}