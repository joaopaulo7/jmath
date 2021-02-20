/*
 * jmath.h
 * 
 * Copyright 2020 João Paulo Paiva Lima <joao.lima1@estudante.ufla.br>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include "stdio.h"
//CONSTANTES----------------------------------------------
double getE(){
    return 2.718281828459045;
}

double getPi(){
    return 3.141592653589793;
}

//FATORIAL----------------------------------------------------
double fat(unsigned x){
    double y = 1;
    while(x > 1)
        y *= x--;
    return y;
}


//EXPONENCIAIS--------------------------------------------
double pow(double x, int a){
    double y = 1;
    while(a > 0)
    {
        y *= x;
        a--;
    }
    return y;
}

int log2(int x){
    if(x < 0)
        throw(0/0);
    
    int y = 0;
    while(x >= 2)
    {
        x /= 2;
        y++;
    }
    return y;
}

double ln(double x){
    if(x <= 0)
        throw(0/0);
    
    int n = 0;
    
    if(x < 0.625)
    {
        while(x < 0.625)
        {
            x *= 2;
            n++;
        }
        n *= -1;
    }
    else if(x > 1.25)
    {
        while(x > 1.25)
        {
            x /= 2;
            n++;
        }
    }
    
    x = 1 - x;
    double y = 0, p = x;
    int i = 1;
    while(p != 0 and i < 35)
    {
        y -= p/i;
        p *= x;
        i++;
    }
    return y + 0.6931471805599451*n;
}

double log10(double x){
    int n = 0;
    while(x >= 10)
    {
        x /= 10;
        n++;
    }
    return ln(x)/2.302585092994045 + n;
}

double log(double x, double a){
    int n = 0;
    while(x >= a)
    {
        x /= a;
        n++;
    }
    return ln(x)/ln(a) + n;
}

double exp(double x){
    if(x >= 1)
    {
        int n = int(x);
        x -= n;
        double y = 1, p = x, f = 1;
        for (int i = 2; i < 19; i++)
        {
            y += p/f;
            f *= i;
            p *= x;
        }
        return y*pow(getE(), n);
    }
    else
    {
        double y = 1, p = x, f = 1;
        for (int i = 2; i < 19; i++)
        {
            y += p/f;
            f *= i;
            p *= x;
        }
        return y;
    }
}

double pow(double a, double x){
    return pow(a, int(x))*exp((x - int(x))*ln(a));
}



//TRIGONOMETRICAS-------------------------------------

double pitagoras(double x0, double x1){
    return pow( x0*x0 + x1*x1, 0.5);
}

double cos(double x){
    while(x > getPi())
        x -= getPi()*2;
        
    double y = 1, fat = 2, po = x*x;
    x = po;
    for(int i = 2; i < 15; i++)
    {
        if(i%2 == 0)
            y -= po/fat;
        else
            y += po/fat;
        fat *= 2*i-1;
        fat *= 2*i;
        po *= x;
    }
    
    return y;
}

double sin(double x){
    
    while(x > getPi())
        x -= getPi()*2;
    
    double y = x, fat = 6, po = x*x*x;
    x = x*x;
    
    for(int i = 2; i < 15; i++)
    {
        if(i%2 == 0)
            y -= po/fat;
        else
            y += po/fat;
        fat *= 2*i;
        fat *= 2*i+1;
        po *= x;
    }
    
    return y;
}

double tan(double x){
    return sin(x)/cos(x);
}

//INVERSAS----------------------------------------------------

double arcsin(double x){
    //Metodo de Newton
    double x0;
    if(x > 0.70710678118655)
        x0 = 0;
    else
        x0 = getPi();
    
    for (int i = 0; i < 10; i++)
        x0 = x0 - ((sin(x0)-x)/cos(x0));
    
    return x0;
}

double arccos(double x){
    //Metodo de Newton
    double x0;
    if(x > 0.70710678118655)
        x0 = getPi()/4;
    else
        x0 = -getPi()/4;
        
    for (int i = 0; i < 10; i++)
        x0 = x0 + ((cos(x0)-x)/sin(x0));
        
    return x0;
}

double arctan(double x){
    return arcsin(x/pitagoras(1, x));
}



//HIPERBOLICAS---------------------------------------------

double cosh(double x){
    double y = 1, fat = 2, po = x*x;
    for(int i = 2; i <20; i++)
    {
        y += po/fat;
        fat *= 2*i-1;
        fat *= 2*i;
        po *= x;
        po *= x;
    }
    return y;
}

double sinh(double x){
    
    double y = 0, fat = 1, po = x;
    for(int i = 1; i < 20; i++)
    {
        y += po/fat;
        fat *= 2*i;
        fat *= 2*i+1;
        po *= x;
        po *= x;
    }
    
    return y;
}
