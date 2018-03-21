#include <iostream>
#include <string>
#include <list>


using namespace std;

class DocPart
{
public:
    string text;
    virtual string toHTML()=0;
    virtual string toText()=0;
    virtual string toLatex()=0;
};

class Text : public DocPart
{
    string toHTML()
    {
        return text;
    }
    string toLatex()
    {
        return text;
    }
    string toText()
    {
        return text;
    }

};

class Bold : public DocPart
{
 string toHTML()
 {
     return "<b>" + text + "<b>";
 }
    string toLatex()
    {
        return "\\textbf{"+text+"}";
    }
    string toText()
    {
        return text;
    }

};

class HyperLink : public DocPart
{
public:
    string URL;
    string toHTML()
    {
        return "<a hred ='" + URL + "'>"+ text + "</a>";
    }
    string toLatex()
    {
        return "\\href{"+URL+"}{"+text+"}";
    }
    string toText()
    {
        return text;
    }

};

class Document
{
public:
    list<DocPart*> docpart;
    string toHTML()
    {
        string out= "";
        for(DocPart* d: docpart)
        {
            out += d->toHTML();
        }
        return out;
    }
    string toLatex()
    {
        string out= "";
        for(DocPart* d: docpart)
        {
            out += d->toLatex();
        }
        return out;
    }
    string toText()
    {
        string out= "";
        for(DocPart* d: docpart)
        {
            out += d->toText();
        }
        return out;
    }
};


int main()
{
    Document d;
    Text t;
    t.text = "kp2";
    Bold t2;
    t2.text = "cachorros";
    HyperLink t3;
    t3.text = "elquelolea";
    t3.URL = "www.EQLL.com";
    d.docpart.push_back(&t);
    d.docpart.push_back(&t2);
    d.docpart.push_back(&t3);


}