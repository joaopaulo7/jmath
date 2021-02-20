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
double const getE(){
    return 2.718281828459045;
}

double const getPi(){
    return 3.141592653589793;
}

const static long int vetorFatorial[21]= {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
const static double vetorFatorial1[21]= {5.10909421717094e+19, 1.12400072777761e+21, 2.58520167388850e+22, 6.20448401733239e+23, 1.55112100433310e+25, 4.03291461126606e+26, 1.08888694504184e+28, 3.04888344611714e+29, 8.84176199373970e+30,
                                                                2.65252859812191e+32, 8.22283865417792e+33, 2.63130836933694e+35, 8.68331761881189e+36, 2.95232799039604e+38, 1.03331479663861e+40, 3.71993326789901e+41, 1.37637530912263e+43, 5.23022617466601e+44, 2.03978820811974e+46, 8.15915283247898e+47,};

//FATORIAL----------------------------------------------------
double fat(unsigned x){
    if(x < 21)
        return vetorFatorial[x];
    else if( x < 41)
        return vetorFatorial1[x - 21];
    double y = vetorFatorial1[20];
    while(x > 40)
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
            y += p/vetorFatorial[i];
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
            y += p/vetorFatorial[i];
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
    
    
    if(x > 0.70710678118655)
        x0 = 0;
    else
        x0 = getPi()/2;
    
    for (int i = 0; i < 10; i++)
        x0 = x0 - ((sin(x0)-x)/cos(x0));
    
    if(sign)
        return -x0;
    else
        return x0;
}

double arccos(double x){
    //Metodo de Newton
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
    
    
    if(x > 0.70710678118655)
        x0 = getPi()/4;
    else
        x0 = 3*getPi()/4;
        
    for (int i = 0; i < 10; i++)
        x0 = x0 + ((cos(x0)-x)/sin(x0));
    
    if(sign)
        return getPi() -x0;
    else
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
