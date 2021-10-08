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
#include <iostream>
#include "jomath.hpp"

int main()
{
    numComplexo tst, tst1, tst2;
    tst.real = 2.5;
    tst.imag = 4;
    
    tst1.real = 2.5;
    tst1.imag = 2;
    
    tst2.real = 0;
    tst2.imag = 1;
    
    for(int i = 0; i < 20; i++)
    {
        printf("%.16f\n", arcsin(1 - pow(0.1, i)));
    }
    printf("%.16f\n", arcsin(sin(0.5)));
    printf("%.16f\n", sin(0.5));
    printf("%.16f\n", arccos(cos(0.5)));
    printf("%.16f\n", cos(0.5));
    std::cout<< pow(tst, tst1) << std::endl;
    std::cout<< ln(tst) << std::endl;
}

