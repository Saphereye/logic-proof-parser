#include <iostream>
#include <cassert>
#include "logic.h"

using namespace std;

void testLogic() {
    assert(Logic::infixToPrefix("(a*b)>(a+c)") == ">*ab+ac");
    assert(Logic::infixToPrefix("a*b>a+c") == ">*ab+ac");
    assert(Logic::infixToPrefix("(a*b>a)+c") == "+>*abac");
	debug("Output 1", Logic::infixToPrefix("((~(~(o*i)))*(((w>f)+(l>b))+((~c)+(c>b))))"));
	debug("Output 2", Logic::infixToPrefix("((~(~(~(((~((~(~(~(((~n)>(~j))>((p>a)>(~v))))))>((~((((k+g)*(f*v))>((d>g)+(b+u)))+((~(q*m))*((q+m)>(u>i)))))>(((((l>r)>(c>m))*((r*d)>(k>n)))>((~(m*i))>((k+b)+(~w))))*((((n*h)+(~y))+((z*z)*(a>i)))>(((~d)>(e>z))>((n+v)>(e+v))))))))>((~(~(~(((~(x+l))+((~a)*(a>l)))+(((~d)>(q*y))+((c>o)*(i*k)))))))>(((((((~c)*(i*s))>((v>l)+(f>m)))*(((~k)>(k*g))+((~l)>(q>t))))*((((~r)*(d*g))*((~g)>(~e)))>(~((h>s)*(o+u)))))*(((~((l*y)>(~p)))*(((v>h)>(h>y))*(~(o*f))))*(~(((r+n)>(~s))*((e+p)*(n*f))))))*(~(((~((~t)*(i+a)))*(~(~(m*y))))+((((o+i)*(r+u))>((p+v)+(m+v)))+((~(p+c))*(~(h>w)))))))))+(~((~(((~(~(~(~z))))>(~((~(~l))*(~(p*t)))))>(((~((r+n)*(a>o)))+(((g>c)+(y*k))*((e>k)+(f>x))))+((~((o*b)+(e*h)))+(((a*s)*(~s))*((w*y)>(x+e)))))))+(((((~((d*c)+(m+f)))*(((z>s)+(s>x))>((f+k)*(~t))))+((((s>u)>(~x))+((e>j)>(f*u)))+((~(z>f))>((l+d)>(q>u)))))+(~(((~(b>x))+(~(~j)))*((~(t+j))*(~(p>c))))))+((~((~(~(g+l)))*(((d>b)*(~r))>((j+z)*(g+j)))))>(~(~((~(c+g))>((e*n)>(g*e)))))))))))))*(~((~((((~((((((l+c)*(l*n))*((m>w)>(r+j)))*(~((~f)*(h*k))))*((((~w)+(~j))+((~d)>(h>s)))+(~((~b)*(~a)))))>(((~((w>b)+(~b)))>(((i+i)>(~g))*((u*y)+(b>b))))>(((~(~n))*((d>j)*(a>t)))>(~(~(~p)))))))>(((((~(~(~r)))*(~((u*t)+(y>g))))>((((v>n)>(q*k))*((u>l)*(c>m)))>((~(o*v))>(~(c*c)))))*((~(((o>d)>(g+o))*((x>z)*(d*g))))>(((~(~h))>((p>e)+(g+y)))>(((t*g)*(n>b))*((n>z)>(p>h))))))*(((((~(e>i))>((v>s)*(f>l)))+((~(l*e))*((a+a)+(t*v))))*((((c*u)+(x>e))*((s*n)+(n*k)))+(((s+u)+(d+y))+((~i)*(s+r)))))>(((((m+h)>(i*t))>((~u)+(f*z)))+((~(q>g))+((i*d)*(e*e))))*((((i+u)>(x*g))>(~(b>d)))>(((~z)*(w>v))*((l>v)*(r*t))))))))>(((((~(~((f*g)*(j*h))))*(((~(r>y))+((g>g)*(~q)))*(((f*j)>(s>e))*((n+d)*(v+f)))))*(~(((~(u+k))*((q*q)>(d>f)))>(((x*c)>(k*o))>((~a)*(d+l))))))+((((~((d>i)+(~e)))>(((~p)+(g*r))*(~(v+x))))>(~((~(y+u))*((u+a)*(~u)))))>((~(~((~f)+(~e))))>((((~e)+(~h))>((i>s)>(m*o)))*(~((~r)*(c>b)))))))*(~((((((p>k)>(r>f))>(~(h*l)))*(~(~(m>n))))+(~(~((g+i)+(u>a)))))*(((((e+i)>(y*v))+(~(~b)))*(((n+w)*(a>x))*((w>l)*(~p))))>(~(((o>n)+(j>i))>((c*x)+(f*y)))))))))*(((((((((~n)>(z>j))>((b*b)+(~u)))+(((~r)*(b+g))>((i>p)>(~n))))+(~(((t*g)+(c*v))>(~(v>d)))))*(((((m*v)+(w+r))*((n+k)*(~g)))>(((c*r)*(g*l))+((a+y)+(~c))))*((~((s>h)>(c>x)))+(((x*u)>(~e))>((u+w)*(p+i))))))*((~((((~j)>(~m))*((s*s)>(t*q)))+(~(~(o+b)))))+(~(~(((q>w)>(w*n))*((c+z)>(n>i)))))))*(~(~((~(((c*k)+(b>c))>((~p)*(~o))))*((((d+f)*(w*p))+((q*x)+(m+v)))>(((h>j)>(z*r))+((m>z)*(d+x))))))))*((~(((~(~(~(~z))))*(((~(n+p))>((s>q)>(r*m)))*(~(~(s*v)))))*(~((~((~j)+(b>v)))>((~(j+w))+((j+f)>(q>t)))))))*(((~((((d>m)>(c>h))>(~(t>w)))>(~(~(~v)))))+(((~((n>b)*(l+l)))+((~(p*w))+((z*m)+(~o))))*((~((j+l)*(n+i)))*(((d>e)+(p*u))>((z>h)>(y*r))))))+((((~(~(x*b)))>(((~a)*(d>q))*((x>b)*(~z))))>(((~(~a))*(~(~l)))*(((w>t)>(~h))*(~(~k)))))>(((~((l*a)+(i+l)))*(((x>a)>(c+j))>((~w)+(m>q))))>((~(~(m*a)))+(((d>t)+(~g))*((h*j)*(x>n)))))))))))+((((((((((~(f+v))+((~c)>(~t)))*(((~k)*(a>e))>(~(~d))))+((((h*r)*(p>q))>((o*l)*(h+g)))+(~(~(t*i)))))>(((~((g*h)*(m>b)))+(~((f>y)+(~r))))>(~(~((k>t)+(u*r))))))+((((~((~y)>(r+t)))>((~(g+j))*((y>f)+(e+p))))*((((c>m)>(v>c))+((~q)+(l+r)))*(((r+t)>(p>g))+((t*c)>(x>u)))))*(~(~(((q*r)*(~w))>((c*w)+(a+z)))))))+((((~((~(~e))+((a*s)*(~e))))*(((~(a>j))+((e>w)*(~j)))>(~((b>b)+(v+b)))))+(((((r>f)+(r>s))*(~(a*q)))*(((i>z)>(i+b))*(~(r*c))))>(((~(u>s))+((j+r)>(i>m)))*((~(h+s))>((t*q)+(v+l))))))>((((((f>b)>(g>a))>((s*m)>(s*z)))+(~((u+r)>(i+n))))+(((~(~d))*((o+h)*(k+q)))*(((e+l)+(h*g))*((k+u)+(c*w)))))*(((~((a*z)*(e*e)))+(((o>z)+(c>j))*((d+y)>(~o))))*(((~(t+d))>((s>r)*(j+t)))+(((r+t)+(l+z))>(~(q*g))))))))+(((~((((~(~v))>(~(m>n)))+(((~y)+(c*b))>((~x)+(l+s))))*(~(((~s)>(g>u))*((q+a)*(f+p))))))*(~(((((j>o)+(a+k))*(~(~s)))>(~((q+h)>(~c))))+((~((l+z)+(i*x)))*(((g*j)>(j>f))>((b*o)+(c*e)))))))+((((~(~((e+j)+(g+p))))*(~(~(~(e*p)))))>(~((((i>d)>(t*k))+(~(~q)))>((~(c+o))>((q*k)*(p+v))))))*((((((c+d)*(n*k))*((~j)+(~v)))*(((j+r)>(t*p))*((j*l)>(f+m))))*(~(~((~l)*(~e)))))+((~((~(d>a))*((x>y)+(~o))))>((((h>l)*(~d))>((e*j)+(~w)))*(~((o+m)>(l+x)))))))))*(((~(~((((~(~m))*((f+x)+(~h)))*(~((t*v)*(f*s))))*((~((v*u)*(o+b)))+(((~d)+(p*g))>((~j)>(b>y)))))))*(((~(((~(v+f))>((e+m)+(t>w)))+(((v+a)>(e+p))+((q>x)*(~v)))))*(((((~l)>(f>g))+(~(n>x)))+(~((f+a)>(q+v))))+(~(~(~(~f))))))>(((((~(l>i))+((~z)>(y*f)))>(((d*t)*(h+d))*((o*g)>(~r))))+((((p+s)*(x*g))+((i*m)>(k>o)))*(((c+u)*(~p))*(~(p>z)))))>(((~((w+h)*(u+p)))+(((s+f)+(~r))+((t>r)>(x>x))))*((((~g)>(s+y))+(~(g+s)))*(((k*h)>(q*g))+((g+y)+(a>t))))))))+(((~(((((~q)*(s*n))>((b+f)*(h>s)))>(((i>b)*(q+f))+((o>m)+(x+u))))>((~((j>r)>(d+b)))*(((y+f)>(n+s))*((n*c)*(f>s))))))*(~((((~(c>r))+((o>y)>(p>y)))*(((m>x)+(q>e))+(~(q+a))))*(((~(~q))>((g*c)>(o*x)))+((~(~o))+((g>t)+(~h)))))))*(((((((b*p)+(w+j))>((~y)+(a+x)))>((~(w*d))*((c*j)>(d+d))))>(((~(v+z))+((~v)+(~v)))*((~(g*c))+((t*p)+(x>y)))))>(~(((~(b*c))>((p>n)*(q+a)))*((~(b*z))>((l*b)*(~q))))))*(~(((((g>h)+(p>l))+(~(w+x)))>(((e>b)*(s+a))>((b*y)+(~w))))*(~(((~g)>(~d))+((z+c)+(h+z))))))))))>(((((((~(((h>x)*(i*f))>((j*w)*(g+k))))*((((n+b)>(e>e))+((x>b)*(d+u)))+(~((v>e)+(p*o)))))*(~(~(~(~(~r))))))*(((~(((r*f)+(f>y))>((m>c)+(g+a))))*(((~(d>y))+((q>c)>(x*x)))>(((~f)*(c*h))*(~(~w)))))>((~(((n>i)*(t>c))>((~a)>(k+t))))+(~(((i*l)*(l+e))+((d>c)>(q*t)))))))>(~((((((u>t)>(~z))>(~(e>b)))>(((p+x)>(a+x))*((n*j)>(g+q))))>((~((b*t)>(b*t)))>(((~y)*(w*n))+((n>j)+(q>k)))))*(((~(~(~l)))*(((e*f)+(~z))>((p*a)+(g*u))))>((((~w)>(n+l))>((u+u)+(e+g)))+(((b+a)*(x>z))>((z*f)+(~t))))))))*(((((~(((~f)+(t+j))*((v+u)*(r*u))))*((((~i)+(v+l))>((i+n)+(u*b)))>(~((v>e)*(k*g)))))*((((~(x*f))+((g+z)*(a+v)))+(~(~(t*m))))>((((~p)*(i>r))*(~(~y)))+(~((f+z)>(~n))))))>(~(~((((a>l)>(p*a))>((n>d)+(~d)))+(((l*n)+(~r))>((j*v)>(b+e)))))))*(((((((j*m)+(u*p))*((t>p)*(~f)))+(((~m)+(i+h))>((~o)+(q+b))))+(((~(d*n))*((~n)>(j>o)))*((~(k>m))*(~(a+a)))))+(~((((c*m)*(x+x))>(~(v>w)))>(((y*q)+(l>r))+((d+r)>(x*f))))))*((((~((o*c)>(l*q)))+(((o+f)*(g*e))>(~(d+k))))*(((~(h+e))*(~(j>x)))+(((~s)>(j*v))>((i*p)+(~g)))))*(((((~m)>(w>g))*(~(r+m)))*((~(i+k))>((~e)+(g+m))))>((~((~s)+(g*z)))+(((w+h)+(f+v))*((~m)+(a+m)))))))))*(((((((~((l>h)+(a>b)))+(((~c)*(x+u))+((w>h)*(d+p))))>(~(((v*v)+(~p))*((m+c)*(o*a)))))>(((((g*n)*(r>p))*(~(o*m)))>(((i*f)*(~u))*(~(~j))))>((((y>e)>(w+y))*((v>k)+(~j)))*(((~h)*(~t))+(~(h+w))))))>(~(~((((t>c)+(g*h))*((j>k)+(e>b)))>(((t>d)+(x>j))>((~e)*(~w)))))))>(((((((e+n)*(~x))*((~n)+(e*w)))+((~(f*x))+(~(r>o))))+(~(((z*x)*(~g))>((~r)+(p>w)))))+(((((~w)*(t*x))+((b*y)+(l+c)))>(~((j*n)*(c*i))))*((((~u)>(~p))>(~(e+d)))>((~(t>e))+((~i)>(n*v))))))+(~(((((i*k)*(x*b))*((w>y)+(z>n)))+(((h>p)>(~p))>((~y)+(n>d))))*(~(~((z+g)+(~y))))))))*((((~(~((~(q+e))>((i*s)+(d+o)))))>(((~((j>d)+(x+o)))>(((~m)+(v+p))+(~(~v))))+((((w*w)+(~g))+((~l)*(n+f)))+(~((i*r)>(~h))))))>((((((o>e)>(d>a))+((~c)+(~z)))>((~(~z))*((c+q)>(h*v))))>((((~k)*(e>u))+((u>b)>(v>s)))+(((g+x)+(j>p))>((~h)*(f+l)))))+((((~(g+l))>((t>u)*(~b)))+(((~h)+(r>v))*((r>k)*(~b))))*(~(~(~(c>r)))))))>(((((((v>g)+(x+o))+((x*e)>(g>t)))>(((r>i)+(c*p))>((~z)>(y*n))))+((((y+e)>(k+c))>((h>m)*(l+m)))>(((u+n)+(x>d))>((~w)+(~l)))))>(((((g*j)>(c+m))+((~m)*(y>i)))>(((~p)>(j+m))>((z*z)+(f*n))))*((~((v*k)*(k+e)))>((~(z>h))+((u*y)+(l*g))))))+((((((o*f)*(r>f))*((d>w)>(v>m)))*(~((~x)*(r+n))))>((((e+v)*(~n))>((n+b)*(~s)))+(((p>k)*(p+b))>((~n)>(s*v)))))*(((((b*o)+(h*n))+((j+l)>(b>t)))+(((i*p)+(e+j))>((z+w)+(~e))))*((((~s)*(~b))>((~u)>(d+g)))+(~(~(g>i))))))))))))))"));
}

void testParseTreeToInfix() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', new Logic::Operator('~', &a), &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator dis('+', &c, &c);
	Logic::Operator dis2('+', &dis, &c);
	Logic::Operator head('+', &impl, &dis2);
	debug("Infix from parse tree", Logic::parseTreeToInfix(&head));
}

void testParseTreeHeight() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', new Logic::Operator('~', &a), &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator dis('+', &c, &c);
	Logic::Operator dis2('+', &dis, &c);
	Logic::Operator head('+', &impl, &dis2);
	debug("Height", Logic::getParseTreeHeight(&head));
}

void testParseTreeVal() {
	Logic::Operator p('p');
	Logic::Operator q('q');
	Logic::Operator head('~', &p, &q);

	// map<char, bool> valueMap = {
	// 	{'p', true},
	// 	{'q', false},
	// };
	TruthValStore tvs("pq", 0b01);
	debug("Value", Logic::getParseTreeVal(&head, tvs));
}

void testValStore() {
	// p=F q=T r=T
	TruthValStore tvs("pqr", 0b110);
	tvs.setTruthVal('q', false);
	debug("Truth val of p", tvs.getTruthVal('p'));
	debug("Truth val of q", tvs.getTruthVal('q'));
	debug("Truth val of r", tvs.getTruthVal('r'));
	//debug("Truth val of z", tvs.getTruthVal('z'));
}

void testPrinting() {
	Logic::Operator a('a');
	Logic::Operator b('b');
	Logic::Operator c('c');
	Logic::Operator con('*', new Logic::Operator('~', &a), &b);
	Logic::Operator impl('>', &con, &a);
	Logic::Operator dis('+', &c, &c);
	Logic::Operator dis2('+', &dis, &c);
	Logic::Operator head('+', &impl, &dis2);

	Logic::displayParseTree(&head);
}

void testprefixToParseTree() {
	string test = "~(a+b)";
	debug(test, Logic::parseTreeToInfix(Logic::prefixToParseTree(Logic::infixToPrefix(test))));
}



int main() {
	debug("debug", 69);
	trace("trace");
	todo("todo");
	//error("error");
    testLogic();
    testParseTreeToInfix();
	testParseTreeHeight();
	testParseTreeVal();
	testValStore();
	testprefixToParseTree();
	testPrinting();
    return 0;
}

