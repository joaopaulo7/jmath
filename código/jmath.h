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
 
#include <stdio.h>
#include "jmath_constants.h"

//FATORIAL----------------------------------------------------

double fat(unsigned x){
    if(x < 21)
        return jmath_fatorial[x];
    else if( x < 41)
        return jmath_fatorial1[x - 21];
    double y = jmath_fatorial1[20];
    while(x > 40)
        y *= x--;
    return y;
}


//EXPONENCIAIS--------------------------------------------

double pow(double x, unsigned a){
    double y = 1;
    
    if(a == 0)
        return 1;
        
    while(a > 1)
    {
        if(a%2 == 1)
        {
            y *= x;
            a--;
        }
        x *= x;
        a /= 2;
    }
    return y*x;
}

double pow(double x, int a){
    double y = 1;
    char sign = 0;
    
    if(a == 0)
        return 1;
    
    if(a < 0)
    {
        sign = 1;
        a *= -1;
    }
    
    while(a > 1)
    {
        if(a%2 == 1)
        {
            y *= x;
            a--;
        }
        x *= x;
        a /= 2;
    }
    
    if(sign)
        return 1/(y*x);
    else
        return y*x;
}

int log2(int x){
    int y = 0;
    while(x >= 2)
    {
        x /= 2;
        y++;
    }
    return y;
}

double ln(double x){
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
    if(x >= 1 or x <= -1)
    {
        char sign= 1;
        if(x < 0)
        {
            x *= -1;
            sign = -1;
        }
        int n = int(x);
        x -= n;
        
        double y = 1, p = x;
        for (int i = 1; i < 18; i++)
        {
            y += p/jmath_fatorial[i];
            p *= x;
        }
        if(sign > 0)
            return y*pow(getE(), n);
        else
            return 1/(y*pow(getE(), n));
    }
    else
    {
        double y = 1, p = x;
        for (int i = 1; i < 18; i++)
        {
            y += p/jmath_fatorial[i];
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
        
    double y = 1, po = x*x;
    x = po;
    for(int i = 1; i < 15; i++)
    {
        if(i%2 == 0)
            y += po/fat(2*i);
        else
            y -= po/fat(2*i);
        po *= x;
    }
    
    return y;
}

double sin(double x){
    
    while(x > getPi())
        x -= getPi()*2;
    
    double y = x, po = x*x*x;
    x = x*x;
    
    for(int i = 1; i < 15; i++)
    {
        if(i%2 == 1)
            y -= po/fat(2*i+1);
        else
            y += po/fat(2*i+1);
        po *= x;
    }
    
    return y;
}

double tan(double x){
    return sin(x)/cos(x);
}


//INVERSAS----------------------------------------------------

double arccos(double x){
    double x0;
    char sign = 0;
    
    if(x <= 0)
    {
        sign = 1;
        x *= -1;
    }
    if(x > 0.999992)
    {
        x = x*x;
        if(x >= 1)
            x0 =  1 - x;
        else
            x0 =  pow( 1 - x, 0.5);

        if(sign)
            return getPi() - x0;
        else
            return x0;
    }
    
    //Metodo de Newton
    x0 = getPi()/4;
        
    for (int i = 0; i < 10; i++)
        x0 = x0 + ((cos(x0)-x)/sin(x0));
    
    if(sign)
        return getPi() -x0;
    else
        return x0;
}

double arcsin(double x){
    double x0;
    char sign = 0;
    if(x <= 0)
    {
        sign = 1;
        x *= -1;
    }
    if(x > 0.999992)
    {
        x = x*x;
        
        if(x >= 1)
            x0 =  1 - x;
        else
            x0 = pow( 1 - x, 0.5);

        if(sign)
            return x0 - getPi()/2;
        else
            return getPi()/2 - x0;
    }
    
    //Metodo de Newton
    x0 = getPi()/4;
    
    for (int i = 0; i < 10; i++)
        x0 = x0 - ((sin(x0)-x)/cos(x0));
    
    if(sign)
        return -x0;
    else
        return x0;
}

double arctan(double x){
    return arcsin(x/pitagoras(1, x));
}


//HIPERBOLICAS---------------------------------------------

double cosh(double x){
    double ex = exp(x);
    return (ex + 1/ex)/2;
}

double sinh(double x){
    double ex = exp(x);
    return (ex - 1/ex)/2;
}

double tanh(double x){
    double e2x = exp(2*x);
    return (e2x - 1)/(e2x + 1);
}
