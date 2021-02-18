/*
 * jomath.hpp
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


#include "jmath.h"

struct numComplexo{
    double real;
    double imag;
    
    //DEFINIÇAO DE OPERADORES---------------------------------------------------------------------------
    
    //SOMA
    friend numComplexo operator+(const numComplexo& n0, const numComplexo& n1){
        numComplexo aux;
        aux.real = n0.real + n1.real;
        aux.imag = n0.imag + n1.imag;
        return aux;
    }
    friend numComplexo operator+(const numComplexo& n0, const double& n1){
        numComplexo aux;
        aux.real = n0.real + n1;
        return aux;
    }
    
    //SUBTRAÇAO
    friend numComplexo operator-(const numComplexo& n0, const numComplexo& n1){
        numComplexo aux;
        aux.real = n0.real - n1.real;
        aux.imag = n0.imag - n1.imag;
        return aux;
    }
    friend numComplexo operator-(const numComplexo& n0, const double& n1){
        numComplexo aux;
        aux.real = n0.real - n1;
        return aux;
    }
    
    //MULTIPLICACAO
    friend numComplexo operator*(const numComplexo& n0, const numComplexo& n1){
        numComplexo aux;
        aux.real = n0.real*n1.real - n0.imag*n1.imag;
        aux.imag = n0.imag*n1.real + n1.imag*n0.real;
        return aux;
    }
    friend numComplexo operator*(const numComplexo& n0, const double& n1){
        numComplexo aux;
        aux.real = n0.real*n1;
        aux.imag = n0.imag*n1;
        return aux;
    }
    
    //DIVISAO
    friend numComplexo operator/(const numComplexo& n0, const numComplexo& n1){
        numComplexo aux;
        double div = n1.real*n1.real + n1.imag*n1.imag;
        aux.real = (n0.real*n1.real + n0.imag*n1.imag)/div;
        aux.imag = (n0.imag*n1.real - n1.imag*n0.real)/div;
        return aux;
    }
    friend numComplexo operator/(const numComplexo& n0, const double& n1){
        numComplexo aux;
        aux.real = n0.real/n1;
        aux.imag = n0.imag/n1;
        return aux;
    }
};



//OPERAÇOES COMPLEXAS COM NUMEROS COMPLEXOS------------------------------------------

//EXPONENCIAIS---------------------------------------------
numComplexo ln(numComplexo x){
    numComplexo y;
    double h = pitagoras(x.real, x.imag);
    y.real = ln(h);
    y.imag= arcsin(x.imag/h);
    return y;
}

numComplexo pow(numComplexo a, double x){
    numComplexo y;
    //y.real = cos()
    return y;
}

numComplexo powi(double a){
    numComplexo y;
    y.real = cos(ln(a));
    y.imag = sin(ln(a));
    return y;
}

numComplexo exp(numComplexo a){
    numComplexo y;
    y.real = cos(a.imag);
    y.imag = sin(a.imag);
    y = y * exp(a.real);
    return y;
}


//TRIGONOMETRICAS-------------------------------------
numComplexo cos(numComplexo x){
    numComplexo y;
    y.real = cos(x.real)*cosh(x.imag);
    y.imag = - sin(x.real)*sinh(x.imag);
    return y;
}

numComplexo sin(numComplexo x){
    numComplexo y;
    y.real = sin(x.real)*cosh(x.imag);
    y.imag = cos(x.real)*sinh(x.imag);
    return y;
}

numComplexo tan(numComplexo x){
    return sin(x)/cos(x);
}
