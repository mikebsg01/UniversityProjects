/**-------------------------------------------------------------------------------------------------------------------- //
* Programa: Multiplicación de Polinomios & Evaluación de Expresión 
*           Final de una Variable (Algoritmo Shunting Yard).
*
* Descripción: El presente software permite realizar la operación de multiplicación
* entre polinomios (cuya cantidad de terminos por polinomio puede ser variable así 
* como el grado del mismo, además, los coeficientes pueden ser enteros o decimales,
* positivos o negativos). Posteriormente, evalua la expresión del polinomio 
* (final) resultante (cuyo resultado es impreso como un único valor numérico
* con formato en punto flotante).
*
* NOTAS IMPORTANTES: 
* 1.- Los operadores aceptados se encuentran en la clase estática <code>Operators</code> 
* contenida dentro de la clase <code>Expression</code>.
* 2.- El algoritmo cuenta con una modificación para permitir las 
* operaciones con números negativos {@see Expression#parseNegativeNumbers}.
* 3.- Esta versión no soporta funciones trigonometricas o alguna otra
* función u operador que no esté presente dentro del código fuente.
* 4.- Esta versión no soporta las operaciones con polinomios de coeficientes
* fraccionarios (es decir, donde los coeficientes de sus términos no sean
* valores explícitamente enteros o decimales).
*
* @author Michael Brandon Serrato Guerrero <mikebsg01@gmail.com> - Expediente: 258849
* @see {@link https://github.com/mikebsg01|Github_Profile}
* @see {@link https://es.wikipedia.org/wiki/Algoritmo_shunting_yard|Shunting_Yard_Algorithm}
* @version 1.0.0
* -------------------------------------------------------------------------------------------------------------------- //
*/
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

#define debug(x) cout << #x << ": " << x << "\n";
#define println(x) cout << x << "\n";

template <typename T>
class Stack {
public:    
    class stackNode {
    public:
        T element;
        stackNode* next;
    };
private:
    stackNode* head;
    int elementCount;

    stackNode* newNode() {
        stackNode *newNode = new stackNode;
    
        if (!newNode) {
            throw runtime_error("ERROR - Stack<>::newNode(): no memory available.");
        }
    
        return newNode;
    }
public:
    Stack();
    ~Stack();
    T top() const;
    void push(T const& element);
    void pop();
    inline bool empty() const;
    inline int size() const;
};

template <typename T>
class Vector {
private:
    T* vector;
    int elementCount;
public:
    Vector(int size = 0, T defaultValue = T());
    inline bool empty() const;
    void push_back(T const& element);
    T& operator[](int const& position) const;
    inline int size() const;
    int find(T const& element) const;
};

template <typename TX, typename TY>
class Pair {
public:
    TX x;
    TY y;
};

class Expression {
private:
    string expression;
public:
    class Signs {
    public:
        static const char POSITIVE = '+';
        static const char NEGATIVE = '-';

        static bool isSign(const char c);
        static char add(const char sing1, const char sign2, const double coefficient1, const double coefficient2);
        static char multiply(const char sign1, const char sign2);
    };

    class Operators {
    public:
        static const char LEFT_PARENTHESIS = '(';
        static const char RIGHT_PARENTHESIS = ')';
        static const char SUM = '+';
        static const char SUBTRACTION = '-';
        static const char MULTIPLICATION = '*';
        static const char DIVISION = '/';
        static const char POWER = '^';
    };

    class Monomial {
    public:
        char sign;
        double coefficient;
        char variable;
        double exponent;

        Monomial() : sign(0), coefficient(0), variable(0), exponent(0) {};
        Monomial(const Monomial& monomial);
        static Monomial& simplify(const Monomial monomial);
        static bool sameGrade(const Monomial monomial1, const Monomial monomial2);
        static Monomial& ZERO();
        static bool isZero(const Monomial monomial);
        bool operator<(const Monomial& monomial) const;
        bool operator!=(const Monomial& monomial) const;
        bool operator==(const Monomial& monomial) const;
        bool hasVariable() const;
        Monomial& add(Monomial monomial) const;
        Monomial& multiply(Monomial monomial) const;
        string toString() const;
    };

    class Polynomial {
    private:
        Vector<Monomial> monomials;
    public:
        Polynomial() {}
        Polynomial(const Polynomial& polynomial);
        inline int size() const;
        Polynomial* push(Monomial const& element);
        Monomial& operator[](int const& position) const;
        Monomial& at(int const& position) const;
        Polynomial& multiply(Polynomial polynomial) const;
        Vector<Monomial> getMonomials() const;
        string toString() const;
    };

    class RPN {
    private:
        Vector<string> elements;
    public:
        RPN(Vector<string> const& elements);
        Vector<string> getElements() const;
        string toString() const;
    };

    Expression(string expression = string(), bool parseNegativeNumbers = true);
    ~Expression();
    static void removeSpaces(string& expression);
    static void addMissingMultiplicationSigns(string& expression);
    static void parseNegativeNumbers(string &expression);
    static bool isVariable(const char c);
    static bool isNumber(const char c);
    static bool isNumber(const string s);
    static bool isOperator(const char c);
    static bool isParenthesis(const char c);
    static int toDigit(const char c);
    static double toNumber(string strNumber);
    static string numberToString(double number);
    static int getOperatorPrecedence(const char operatorChar);
    static int getOperatorPrecedenceOnStack(const char operatorChar);
    static int compareOperatorPrecedence(const char operatorX, const char operatorY);
    static int getOperatorAssociativity(const char operatorChar);
    Expression* setExpression(string expression, bool parseNegativeNumbers = true);
    string toString() const;
    Vector<char> getVariables() const;
    int countVariables() const;
    Polynomial& getPolynomial() const;
    RPN& getRPN() const;
    double eval(Vector<Pair<char, double> > values) const;
};

int main() {
    Expression::Polynomial P, Q, R;
    Expression expression;
    Vector<char> variables;
    Vector<Pair<char, double> > values;
    Pair<char, double> temp;
    string s;
    double v;
    int i;

    cout << "\n\tMULTIPLICACION DE POLINOMIOS & EVALUACION DE EXPRESION"
        << "\n\tFINAL CON UNA VARIABLE.\n\n\tAutor: Michael Serrato <mikebsg01@gmail.com>\n\n"
        << "Introduzca el primer polinomio (P): ";
    getline(cin, s);
    P = Expression(s, false).getPolynomial();

    cout << "\nIntroduzca el segundo polinomio (Q): ";
    getline(cin, s);
    Q = Expression(s, false).getPolynomial();

    R = P.multiply(Q);

    cout << "\nPolinomios a multiplicar:\n\n"
         << "Polimomio \"P\": " << P.toString() << "\n"
         << "Polinomio \"Q\": " << Q.toString() << "\n\n"
         << "Polinomio (R) resultante de la multiplicacion: \n\n"
         << "\t" + (s = R.toString()) << "\n\n";

    expression.setExpression(s);
    variables = expression.getVariables();

    for (i = 0; i < variables.size(); ++i) {
        cout << "Introduzca el valor de \"" << variables[i] << "\": ";
        cin >> v;
        temp.x = variables[i];
        temp.y = v;
        values.push_back(temp);
    }

    cout << "\nExpresion en Infijo: " << expression.toString() << "\n"
         << "Expresion en Postfijo: " << expression.getRPN().toString() << "\n";

    printf("Resultado de Evaluacion: %.6f\n", expression.eval(values));
    return 0;
}

template <typename T>
Stack<T>::Stack() {
    this->head = NULL;
    this->elementCount = 0;
}

template <typename T>
Stack<T>::~Stack() {
    while (!this->empty()) {
        this->pop();
    }
}

template <typename T>
inline bool Stack<T>::empty() const {
    return head == NULL;
}

template <typename T>
T Stack<T>::top() const {
    if (this->empty()) {
        throw out_of_range("ERROR - Stack<>::top(): empty stack.");
    }

    return head->element;
}

template <typename T>
void Stack<T>::push(T const& element) {
    stackNode* temp;

    temp = newNode();
    temp->element = element;
    temp->next = head;
    head = temp;
    ++this->elementCount;
}

template <typename T>
void Stack<T>::pop() {
    if (this->empty()) {
        throw out_of_range("ERROR - Stack<>::pop(): empty stack.");
    }

    stackNode *temp;

    temp = head->next;
    delete head;
    head = temp;
    --this->elementCount;
}

template <typename T>
inline int Stack<T>::size() const {
    return this->elementCount;
}

template <typename T>
Vector<T>::Vector(int size, T defaultValue) {
    this->elementCount = 0;
    int i = 0;

    if (size > 0) {
        this->vector = new T[size];

        if (this->vector) {
            throw runtime_error("ERROR - Vector<>::Vector(): no memory available.");
        }

        for (i = 0; i < size; ++i) {
            this->vector[i] = (T) defaultValue;
        }
    }

    this->elementCount = size;
}

template <typename T>
void Vector<T>::push_back(T const& element) {
    size_t n = this->size();
    T* temp = new (nothrow) T[n + 1];

    if (!temp) {
        throw runtime_error("ERROR - Vector<>::push_back(): no memory available.");
    }

    if (n > 0) {
        copy(this->vector, this->vector + n, temp);
        delete[] this->vector;
    }

    this->vector = temp;
    this->vector[n] = element;
    ++this->elementCount;
}

template <typename T>
inline bool Vector<T>::empty() const {
    return this->elementCount == 0;
}

template <typename T>
inline int Vector<T>::size() const {
    return this->elementCount;
}

template <typename T>
int Vector<T>::find(T const& element) const {
    int i;

    for (i = 0; i < this->size(); ++i) {
        if (this->vector[i] == element) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T& Vector<T>::operator[](int const& position) const {
    if (position < 0 or position >= this->size()) {
        throw out_of_range("ERROR - Vector<>::operator[]: position entered out of range.");
    }

    return this->vector[position];
}

bool Expression::Signs::isSign(const char c) {
    return c == Signs::POSITIVE or
        c == Signs::NEGATIVE;
}

char Expression::Signs::add(const char sign1, const char sign2, const double coefficient1, const double coefficient2) {
    return coefficient1 > coefficient2 ? sign1 : sign2;
}

char Expression::Signs::multiply(const char sign1, const char sign2) {
    if (!isSign(sign1) or !isSign(sign2)) {
        throw invalid_argument("ERROR - Expression::Signs::multiply(): arguments are not a valid sign.");
    }

    if (sign1 != sign2) {
        return Signs::NEGATIVE;
    } else {
        return Signs::POSITIVE;
    }
}

Expression::RPN::RPN(Vector<string> const& elements) {
    this->elements = elements;
}

Expression::Monomial::Monomial(const Monomial& monomial) {
    this->sign = monomial.sign;
    this->coefficient = monomial.coefficient;
    this->variable = monomial.variable;
    this->exponent = monomial.exponent;
}

bool Expression::Monomial::operator<(const Monomial& monomial) const {
    Monomial *lhs = &this->simplify(*this),
             *rhs = &this->simplify(monomial);

    if (!lhs->hasVariable() and !rhs->hasVariable()) {
        return lhs->coefficient > rhs->coefficient;
    } else if (lhs->hasVariable() and rhs->hasVariable()) {
        double lhsCoefficient = (lhs->sign == Signs::NEGATIVE ? -1 : 1) * lhs->coefficient;
        double rhsCoefficient = (rhs->sign == Signs::NEGATIVE ? -1 : 1) * rhs->coefficient;
        return lhs->exponent == rhs->exponent ? (lhsCoefficient > rhsCoefficient) : (lhs->exponent > rhs->exponent);
    }
    return lhs->hasVariable() and !rhs->hasVariable();
}

bool Expression::Monomial::operator!=(const Monomial& monomial) const {
    Monomial *lhs = &this->simplify(*this),
             *rhs = &this->simplify(monomial);
    
    return lhs->sign != rhs->sign or
           lhs->coefficient != rhs->coefficient or
           lhs->variable != rhs->variable or
           lhs->exponent != rhs->exponent;
}

bool Expression::Monomial::operator==(const Monomial& monomial) const {
    Monomial *lhs = &this->simplify(*this),
             *rhs = &this->simplify(monomial);

    return lhs->sign == rhs->sign and
           lhs->coefficient == rhs->coefficient and
           lhs->variable == rhs->variable and
           lhs->exponent == rhs->exponent;
}

bool Expression::Monomial::hasVariable() const {
    return this->variable > 0;
}

Expression::Monomial& Expression::Monomial::simplify(const Monomial monomial) {
    Monomial* tmpMonomial = new Monomial(monomial);

    if (tmpMonomial->coefficient == 0) {
        tmpMonomial->sign = Signs::POSITIVE;
        tmpMonomial->variable = 0;
        tmpMonomial->exponent = 1;
    } else if (!tmpMonomial->hasVariable()) {
        tmpMonomial->coefficient = pow(tmpMonomial->coefficient, tmpMonomial->exponent);
        tmpMonomial->exponent = 1;
    }
    return *tmpMonomial;
}

bool Expression::Monomial::sameGrade(const Monomial monomial1, const Monomial monomial2) {
    return monomial1.hasVariable() == monomial2.hasVariable() and
           monomial1.exponent == monomial2.exponent;
}

Expression::Monomial& Expression::Monomial::ZERO() {
    Monomial* tmpMonomial = new Monomial();
    tmpMonomial->sign = '+';
    tmpMonomial->coefficient = tmpMonomial->variable = 0;
    tmpMonomial->exponent = 1;
    return *tmpMonomial;
}

bool Expression::Monomial::isZero(const Monomial monomial) {
    return monomial == Monomial::ZERO();
}

Expression::Monomial& Expression::Monomial::add(Monomial monomial) const {
    Monomial *tmpMonomial1 = &this->simplify(*this),
             *tmpMonomial2 = &this->simplify(monomial);

    if (!this->sameGrade(*tmpMonomial1, *tmpMonomial2)) {
        throw invalid_argument("ERROR - Expression::Monomial::add(): the argument passed is not a monomial of the same grade");
    }

    if (tmpMonomial1->sign == tmpMonomial2->sign) {
        tmpMonomial1->coefficient += tmpMonomial2->coefficient;
    } else {
        double coefficient1 = tmpMonomial1->coefficient;
        double coefficient2 = tmpMonomial2->coefficient;

        tmpMonomial1->sign = Signs::add(tmpMonomial1->sign, tmpMonomial2->sign, coefficient1, coefficient2);
        tmpMonomial1->coefficient = coefficient1 > coefficient2 ? 
                                    (coefficient1 - coefficient2) : (coefficient2 - coefficient1);
    }

    return *tmpMonomial1;
}

Expression::Monomial& Expression::Monomial::multiply(Monomial monomial) const {
    Monomial *tmpMonomial1 = &this->simplify(*this),
            *tmpMonomial2 = &this->simplify(monomial);

    tmpMonomial1->sign = Signs::multiply(tmpMonomial1->sign, tmpMonomial2->sign);
    tmpMonomial1->coefficient = tmpMonomial1->coefficient * tmpMonomial2->coefficient;
    
    if (tmpMonomial1->hasVariable() or tmpMonomial2->hasVariable()) {
        if (tmpMonomial1->hasVariable() and tmpMonomial2->hasVariable()) {
            tmpMonomial1->exponent = tmpMonomial1->exponent + tmpMonomial2->exponent;
        } else {
            tmpMonomial1->exponent = max(tmpMonomial1->exponent, tmpMonomial2->exponent);
        }
        tmpMonomial1->variable = tmpMonomial1->variable ? tmpMonomial1->variable : tmpMonomial2->variable;
        tmpMonomial1 = &this->simplify(*tmpMonomial1);
    }
    return *tmpMonomial1;
}

string Expression::Monomial::toString() const {
    bool showCoefficient = false;
    string s("");

    if (this->sign) {
        s += this->sign;
    }

    if (!this->hasVariable() or this->coefficient != 1) {
        showCoefficient = true;
        s += numberToString(this->coefficient);
    }

    if (this->variable) {
        s += string(showCoefficient ? "*" : "") + this->variable;
    }

    if (this->exponent != 1 and
        (this->hasVariable() and this->exponent != 0)) {
        s += "^" + numberToString(this->exponent);
    }
    
    return s;
}

Expression::Polynomial::Polynomial(const Polynomial& polynomial) {
    int i;

    for (i = 0; i < polynomial.size(); ++i) {
        this->push(polynomial.at(i));
    }
}

inline int Expression::Polynomial::size() const {
    return (this->monomials).size();
}

Expression::Polynomial* Expression::Polynomial::push(Monomial const& element) {
    (this->monomials).push_back(element);
    return this;
}

Expression::Monomial& Expression::Polynomial::operator[](int const& position) const {
    return this->monomials[position];
}

Expression::Monomial& Expression::Polynomial::at(int const& position) const {
    return this->monomials[position];
}

Expression::Polynomial& Expression::Polynomial::multiply(Polynomial polynomial) const {
    int i, j;
    Polynomial* tmpPolynomial = new Polynomial();
    Monomial result;
    Vector<Monomial> monomials;

    for (i = 0; i < this->size(); ++i) {
        for (j = 0; j <  polynomial.size(); ++j) {
            result = (this->at(i)).multiply(polynomial.at(j));
            tmpPolynomial->push(result);
        }
    }

    monomials = tmpPolynomial->getMonomials();
    int n = monomials.size();
    Monomial monomialArray[n];

    for (i = 0; i < n; ++i) {
        monomialArray[i] = monomials[i];
    }

    tmpPolynomial = new Polynomial();
    sort(monomialArray, monomialArray + n);

    for (i = 0; i < n; ++i) {
        result = monomialArray[i];
        j = i + 1;
        while (Monomial::sameGrade(monomialArray[i], monomialArray[j]) and j < n) {
            result = result.add(monomialArray[j]);
            ++j;
        }
        if (!Monomial::isZero(result) or tmpPolynomial->size() == 0) {
            tmpPolynomial->push(result);
        }
        i = j - 1;
    }
    return *tmpPolynomial;
}

Vector<Expression::Monomial> Expression::Polynomial::getMonomials() const  {
    return this->monomials;
}

string Expression::Polynomial::toString() const {
    int i, n = (this->monomials).size();
    string tmp, s("");

    if (n > 0) {
        tmp = this->monomials[0].toString();
        s = tmp;

        if (tmp[0] != Signs::NEGATIVE) {
            s = tmp.substr(1, tmp.length() - 1);
        }
    }

    for (i = 1; i < n; ++i) {
        tmp = this->monomials[i].toString();

        if (i > 0 and !Signs::isSign(tmp[0])) {
            tmp = "+" + tmp;
        }
        s += tmp;
    }
    return s;
}

Vector<string> Expression::RPN::getElements() const {
    return this->elements;
}

string Expression::RPN::toString() const {
    string str;
    int i;

    for (i = 0; i < elements.size(); ++i) {
        str += elements[i];
    }
    return str;
}

Expression::Expression(string expression, bool parseNegativeNumbers) {
    this->setExpression(expression, parseNegativeNumbers);
}

Expression::~Expression() {
    (this->expression).clear();
}

void Expression::removeSpaces(string& expression) {
    int i;

    for (i = 0; i < expression.size(); ++i) {
        if (expression[i] == ' ') {
            expression.erase(i, 1);
            --i;
        }
    }
}

void Expression::addMissingMultiplicationSigns(string& expression) {
    int i;
    char c1, c2;
    string s("");

    for (i = 0; i < expression.size(); ++i) {
        c1 = expression[i];

        if (isVariable(c1) and (i > 0 and 
            isNumber((c2 = expression[i - 1])) or
            isVariable(c2) or c2 == Operators::RIGHT_PARENTHESIS)) {
            s += "*";
        }
        s += c1;
    }
    expression = s;
}

void Expression::parseNegativeNumbers(string& expression) {
    int i, j;
    char c1, c2, c3;
    string s1("");

    for (i = 0; i < expression.size(); ++i) {
        c1 = expression[i];

        if (c1 == Operators::SUBTRACTION and
            (i == 0 or (c2 = expression[i - 1]) == Operators::LEFT_PARENTHESIS or
            (isOperator(c2) and c2 != Operators::RIGHT_PARENTHESIS))) {
            j = i + 1;
            c3 = expression[j];

            if (c3 == Operators::LEFT_PARENTHESIS) {
                int openParenthesis = 1;
                char c4;
                s1 += "(0-(";

                while (openParenthesis > 0) {
                    ++j;
                    c4 = expression[j];
                    s1 += c4;

                    if (c4 == Operators::LEFT_PARENTHESIS) {
                        ++openParenthesis;
                    } else if (c4 == Operators::RIGHT_PARENTHESIS) {
                        --openParenthesis;
                    }
                }

                s1 += ")";
                i = j;
            } else if (isVariable(c3)) {
                    s1 += "(0-" + string(1, c3) + ")";
                    i = j;
            } else if (isNumber(c3)) {
                s1 += "(0-";

                while (isNumber(expression[j])) {
                    s1 += expression[j];
                    ++j;
                }

                s1 += ")";
                i = j - 1;
            }
            continue;
        }
        s1 += c1;
    }
    expression = s1;
}

bool Expression::isVariable(const char c) {
    return c >= 'a' and c <= 'z';
}

bool Expression::isNumber(const char c) {
    return (c >= '0' and c <= '9') or c == '.';
}

bool Expression::isNumber(const string str) {
    int i;

    for (i = 0; i < str.size(); ++i) {
        if (!isNumber(str[i])) {
            return false;
        }
    }
    return true;
}

bool Expression::isOperator(const char c) {
    return isParenthesis(c) or 
        c == Operators::SUM or 
        c == Operators::SUBTRACTION or 
        c == Operators::MULTIPLICATION or 
        c == Operators::DIVISION or 
        c == Operators::POWER;
}

bool Expression::isParenthesis(const char c) {
    return c == Operators::LEFT_PARENTHESIS or 
        c == Operators::RIGHT_PARENTHESIS;
}

inline int Expression::toDigit(const char c) {
    return ((int)(c-'0'));
}

double Expression::toNumber(string strNumber) {
    int i;
    double num = 0, tmp = 0, factor = 0.1;
    bool floatingPoint = false;

    for (i = 0; i < strNumber.length(); ++i) {
        if (strNumber[i] == '.') {
            floatingPoint = true;
        } else if (isNumber(strNumber[i])) {
            tmp = toDigit(strNumber[i]);

            if (!floatingPoint) {
                num = (num * 10) + tmp;
            } else {
                num = num + (tmp * factor);
                factor *= 0.1;
            }
        }
    }

    if (strNumber.length() > 0 and 
        strNumber[0] == Signs::NEGATIVE) {
        num *= -1;
    }
    return num;
}

string Expression::numberToString(double number) {
    ostringstream ss;
    ss << number;
    return ss.str();
}

int Expression::getOperatorPrecedence(const char operatorChar) {
    if (!isOperator(operatorChar)) {
        throw invalid_argument("ERROR - Expression::getOperatorPrecedence(): the argument is not a valid operator.");
    }

    if (operatorChar == Operators::LEFT_PARENTHESIS) {
        return 5;
    } else if (operatorChar == Operators::POWER) {
        return 4;
    } else if (operatorChar == Operators::MULTIPLICATION or 
            operatorChar == Operators::DIVISION) {
        return 3;
    } else if (operatorChar == Operators::SUM or 
            operatorChar == Operators::SUBTRACTION) {
        return 2;
    }
}

int Expression::getOperatorPrecedenceOnStack(const char operatorChar) {
    if (!isOperator(operatorChar)) {
        throw invalid_argument("ERROR - Expression::getOperatorPrecedenceOnStack(): the argument is not a valid operator.");
    }

    if (operatorChar == '(') {
        return 1;
    }

    return getOperatorPrecedence(operatorChar);
}

int Expression::compareOperatorPrecedence(const char operatorX, const char operatorY) {
    if (!isOperator(operatorX) or !isOperator(operatorY)) {
        throw invalid_argument("ERROR - Expression::compareOperatorPrecedence(): arguments are not valid operators.");
    }

    int priorityX = getOperatorPrecedence(operatorX),
        priorityY = getOperatorPrecedenceOnStack(operatorY);

    if (priorityX < priorityY) {
        return -1;
    } else if (priorityX == priorityY) {
        return 0;
    } else if (priorityX > priorityY) {
        return 1;
    }
}

int Expression::getOperatorAssociativity(const char operatorChar) {
    if (operatorChar == Operators::POWER) {
        return -1;
    }
    return 1;
}

Expression* Expression::setExpression(string expression, bool parseNegativeNumbers) {
    int i;

    for (i = 0; i < expression.length(); ++i) {
        expression[i] = tolower(expression[i]);
    }

    this->expression = expression;
    this->removeSpaces(this->expression);

    if (parseNegativeNumbers) {
        this->parseNegativeNumbers(this->expression);
    }

    this->addMissingMultiplicationSigns(this->expression);
    return this;
}

string Expression::toString() const {
    return this->expression;
}

Vector<char> Expression::getVariables() const {
    Vector<char> variables;
    int i = 0;
    char c;

    for (i = 0; i < (this->expression).length(); ++i) {
        c = this->expression[i];

        if (this->isVariable(c) and variables.find(c) == -1) {
            variables.push_back(c);
        }
    }

    return variables;
}

int Expression::countVariables() const {
    Vector<char> variables = this->getVariables();

    return variables.size();
}

Expression::Polynomial& Expression::getPolynomial() const {
    int i, j, n;
    char c;
    bool hasCoefficient;
    Monomial tmp;
    Polynomial* polynomial;

    string expression = this->expression;
    n = expression.length();
    polynomial = new Polynomial();

    if (n > 0) {
        c = expression[0];

        if (!Signs::isSign(c)) {
            expression = "+" + expression;
        }
    }

    for (i = 0; i < n; ++i) {
        tmp = Monomial();
        c = expression[i];

        if (Signs::isSign(c)) {
            tmp.sign = c;
            tmp.exponent = 1;
            hasCoefficient = false;
            j = i = (i + 1);

            if (isNumber(expression[j])) {
                while (isNumber(expression[j])) {
                    ++j;
                }

                tmp.coefficient = toNumber(expression.substr(i, j - i));
                hasCoefficient = true;
            }

            if (expression[j] == Operators::MULTIPLICATION) {
                j = j + 1;
            }

            if (isVariable(c = expression[j])) {
                tmp.variable = c;
                tmp.coefficient = hasCoefficient ? tmp.coefficient : 1;
                j = j + 1;
            }

            if (expression[j] == Operators::POWER) {
                char sign;

                if ((c = expression[j + 1]) == Signs::NEGATIVE) {
                    sign = c;
                    j = j + 1;
                }

                j = i = (j + 1);

                while (isNumber(expression[j])) {
                    ++j;
                }
                tmp.exponent = toNumber(sign + expression.substr(i, j - i));
            }
            i = j - 1;
            polynomial->push(tmp);
        }
    }
    return *polynomial;
}

Expression::RPN& Expression::getRPN() const {
    Stack<char> operators;
    Vector<string> rpnElements;
    string strTemp;
    int i, j, cmp, assoc;
    char c, top;

    for (i = 0; i < (this->expression).length(); ++i) {
        c = this->expression[i];

        if (this->isVariable(c)) {
            rpnElements.push_back(string(1, c));
        } else if (this->isNumber(c)) {
            j = i + 1;
            while (this->isNumber(c = this->expression[j])) {
                ++j;
            }
            rpnElements.push_back((this->expression).substr(i, j - i));
            i = j - 1;
        } else if (isOperator(c)) {

            if (c == Operators::RIGHT_PARENTHESIS) {
                while (!operators.empty() and (top = operators.top()) != Operators::LEFT_PARENTHESIS) {
                    rpnElements.push_back(string(1, top));
                    operators.pop();
                }
                operators.pop();
            } else {
                while (!operators.empty() and 
                    (((assoc = this->getOperatorAssociativity(c)) == 1 and 
                    this->compareOperatorPrecedence(c, operators.top()) < 1) or 
                    (assoc == -1 and this->compareOperatorPrecedence(c, operators.top()) < 0))) {
                    if (!isParenthesis(c)) {
                        rpnElements.push_back(string(1, operators.top()));
                    }
                    operators.pop();
                }
                operators.push(c);
            }
        }
    }
    while (!operators.empty()) {
        rpnElements.push_back(string(1, operators.top()));
        operators.pop();
    }
    return *new RPN(rpnElements);
}

double Expression::eval(Vector<Pair<char, double> > values) const {
    Stack<double> evalStack;
    Vector<string> rpnElements = (this->getRPN()).getElements();
    double operandX, operandY, result;
    string s;
    char c;
    int i, j, pos;

    for (i = 0; i < rpnElements.size(); ++i) {
        s = rpnElements[i];

        if (this->isNumber(s)) {
            evalStack.push(this->toNumber(s));
        } else if (s.size() == 1) {
            c = s[0];

            if (this->isVariable(c)) {
                for (j = 0; j < values.size(); ++j) {
                    if (values[j].x == c) {
                        evalStack.push(values[j].y);
                        break;
                    }
                }
            } else if (isOperator(c)) {
                operandY = evalStack.top();
                evalStack.pop();
                operandX = evalStack.top();
                evalStack.pop();

                if (c == Operators::SUM) {
                    result = operandX + operandY;
                } else if (c == Operators::SUBTRACTION) {
                    result = operandX - operandY;
                } else if (c == Operators::MULTIPLICATION) {
                    result = operandX * operandY;
                } else if (c == Operators::DIVISION) {
                    result = operandX / operandY;
                } else if (c == Operators::POWER) {
                    result = pow(operandX, operandY);
                }
                evalStack.push(result);
            }
        }
    }
    result = evalStack.top();
    evalStack.pop();
    return result;
}

/* --------------------------------------------------------------------------------------------------- //
                                CORRIDAS DE LOS CASOS TÍPICOS
------------------------------------------------------------------------------------------------------ // 

1.  Primer polinomio: P(x) = x^2
    Segundo polinomio: Q(x) = x + 1
    Polinomio resultante: R = x^3+x^2
    Valor de "x": 3
    Expresion en Infijo: x^3+x^2
    Expresion en Postfijo: x3^x2^+
    Resultado de Evaluacion: 36.000000

2.  Primer polinomio: P(x) = x + 1
    Segundo polinomio: Q(x) = x^2 +1
    Polinomio resultante: R = x^3+x^2+x+1
    Valor de "x": 2
    Expresion en Infijo: x^3+x^2+x+1
    Expresion en Postfijo: x3^x2^+x+1+
    Resultado de Evaluacion: 15.000000

3.  Primer polinomio: P(x) = x^2 +1
    Segundo polinomio: Q(x) = x^2 + x + 1
    Polinomio resultante: R = x^4+x^3+2*x^2+x+1
    Valor de "x": 2
    Expresion en Infijo: x^4+x^3+2*x^2+x+1
    Expresion en Postfijo: x4^x3^+2x2^*+x+1+
    Resultado de Evaluacion: 35.000000

4.  Primer polinomio: P(x) = x^3 + 3*X
    Segundo polinomio: Q(x) = x^3
    Polinomio resultante: R = x^6+3*x^4
    Valor de "x": 2
    Expresion en Infijo: x^6+3*x^4
    Expresion en Postfijo: x6^3x4^*+
    Resultado de Evaluacion: 112.000000

5.  Primer polinomio: P(x) = x^3 + 3*X
    Segundo polinomio: Q(x) = 2X^2 + 3*X +1
    Polinomio resultante: R = 2*x^5+3*x^4+7*x^3+9*x^2+3*x
    Valor de "x": -3
    Expresion en Infijo: 2*x^5+3*x^4+7*x^3+9*x^2+3*x
    Expresion en Postfijo: 2x5^*3x4^*+7x3^*+9x2^*+3x*+
    Resultado de Evaluacion: -360.000000

6.  Primer polinomio: P(x) = x^2
    Segundo polinomio: Q(x) = x + 1
    Polinomio resultante: R = x^3+x^2
    Valor de "x": -2.5
    Expresion en Infijo: x^3+x^2
    Expresion en Postfijo: x3^x2^+
    Resultado de Evaluacion: -9.375000

7.  Primer polinomio: P(x) = x^2 + x + 1
    Segundo polinomio: Q(x) = x^3
    Polinomio resultante: R = x^5+x^4+x^3
    Valor de "x": -12.9
    Expresion en Infijo: x^5+x^4+x^3
    Expresion en Postfijo: x5^x4^+x3^+
    Resultado de Evaluacion: -331684.917390

8.  Primer polinomio: P(x) = x^3+3*x
    Segundo polinomio: Q(x) = x^3+2*x^2+x+1
    Polinomio resultante: R = x^6+2*x^5+4*x^4+7*x^3+3*x^2+3*x
    Valor de "x": 3
    Expresion en Infijo: x^6+2*x^5+4*x^4+7*x^3+3*x^2+3*x
    Expresion en Postfijo: x6^2x5^*+4x4^*+7x3^*+3x2^*+3x*+
    Resultado de Evaluacion: 1764.000000

9.  Primer polinomio: P(x) = x^3+2*x^2+ x + 1
    Segundo polinomio: Q(x) = 2*X^3 - 3*x^2 + 4*x - 2
    Polinomio resultante: R = 2*x^6+x^5+5*x^3-3*x^2+2*x-2
    Valor de "x": 1
    Expresion en Infijo: 2*x^6+x^5+5*x^3-3*x^2+2*x-2
    Expresion en Postfijo: 2x6^*x5^+5x3^*+3x2^*-2x*+2-
    Resultado de Evaluacion: 5.000000

------------------------------------------------------------------------------------------------------ */