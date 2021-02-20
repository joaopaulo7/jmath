/*
 * teste.cpp
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
#include "jomath.hpp"

int main()
{
    numComplexo tst;
    tst.real = 1;
    tst.imag = 1.4;
    double teste = getPi()/2 ;
    while(teste >  getPi()/2 - 0.1)
    {
        //printf("%.14f<>", teste);
        //printf("%.14f\n\n", exp(ln(teste)));
        printf("%.14f\n\n", sin(teste));
        printf("%.14f<>", teste);
        printf("%.14f\n\n", arcsin(sin(teste)));
        printf("%.14f\n", teste - arcsin(sin(teste)));
        //printf("%.14f<>", getPi()*teste);
        //printf("%.14f\n", (arcsin(sin(getPi()*teste))));
        teste -= 0.0001;
    }
    
    tst = exp(tst);
    printf("%.14f + %.14fi\n", tst.real, tst.imag);
    tst = ln(tst);
    printf("%.14f + %.14fi\n", tst.real, tst.imag);
    
}

