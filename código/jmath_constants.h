/*
 * jmath_constants.h
 * 
 * Copyright 2021 João Paulo Paiva Lima <joao.lima1@estudante.ufla.br>
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

double const getE(){
    return 2.718281828459045;
}

double const getPi(){
    return 3.141592653589793;
}

const static long unsigned jmath_fatorial[21]= {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800, 
    479001600,6227020800,87178291200,1307674368000,20922789888000, 
    355687428096000,6402373705728000,121645100408832000,2432902008176640000};
    
const static double jmath_fatorial1[20]= {5.10909421717094e+19, 1.12400072777761e+21, 2.58520167388850e+22,
    6.20448401733239e+23, 1.55112100433310e+25, 4.03291461126606e+26, 1.08888694504184e+28, 3.04888344611714e+29,
    8.84176199373970e+30, 2.65252859812191e+32, 8.22283865417792e+33, 2.63130836933694e+35,
    8.68331761881189e+36, 2.95232799039604e+38, 1.03331479663861e+40, 3.71993326789901e+41,
    1.37637530912263e+43, 5.23022617466601e+44, 2.03978820811974e+46, 8.15915283247898e+47};
