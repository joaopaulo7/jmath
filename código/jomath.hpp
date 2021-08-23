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
    
    //SAIDAS
    friend std::ostream& operator<<(std::ostream& os, const numComplexo& n0){
        if (n0.real != 0)
        {
            os << n0.real;
            if(n0.imag < 0)
                os <<" - " << n0.imag*(-1)<<"i";
            else if(n0.imag != 0)
                os <<" + " << n0.imag <<"i";
        }
        else if(n0.imag == 0)
            os << "0";
        else
        {
            if(n0.imag < 0)
                os << n0.imag*(-1)<<"i";
            else if(n0.imag != 0)
                os << n0.imag <<"i";
        }
        
        return os;
    }
};


//OPERAÇOES COMPLEXAS COM NUMEROS COMPLEXOS------------------------------------------

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
    y.imag = + cos(x.real)*sinh(x.imag);
    return y;
}

numComplexo tan(numComplexo x){
    return sin(x)/cos(x);
}


//HIPERBOLICAS---------------------------------------------
numComplexo cosh(numComplexo x){
    numComplexo i;
    i.real = 0;
    i.imag = 1;
    return cos(x * i);
}

numComplexo sinh(numComplexo x){
    numComplexo i;
    i.real = 0;
    i.imag = 1;
    return sin(x * i) * (i * -1);
}

numComplexo tanh(numComplexo x){
    numComplexo i;
    i.real = 0;
    i.imag = 1;
    return tan(x * i) * (i * -1);
}


//EXPONENCIAIS---------------------------------------------
numComplexo exp(numComplexo a){
    numComplexo y;
    y.real = cos(a.imag);
    y.imag = sin(a.imag);
    y = y * exp(a.real);
    return y;
}

numComplexo ln(numComplexo x){
    numComplexo y;
    double h = pitagoras(x.real, x.imag);
    y.real = ln(h);
    y.imag= arcsin(x.imag/h);
    return y;
}

numComplexo pow(numComplexo x, unsigned a){
    numComplexo y;
    
    y.real = 1;
    y.imag = 0;
    
    if(a == 0)
        return y;
    
    while(a > 1)
    {
        if(a%2 == 1)
        {
            y = y*x;
            a--;
        }
        x = x*x;
        a /= 2;
    }
    
    return y*x;
}

numComplexo powi(double a){
    numComplexo y;
    y.real = cos(ln(a));
    y.imag = sin(ln(a));
    return y;
}

numComplexo pow(numComplexo a, numComplexo x){
    numComplexo aux = ln(a), y, i;
    i.real = 0;
    i.imag = 1;
    unsigned intReal = (unsigned) a.real;

    y = pow(a, intReal) * exp(aux*(i * x.imag + a.real - intReal));
    
    return y;
}

