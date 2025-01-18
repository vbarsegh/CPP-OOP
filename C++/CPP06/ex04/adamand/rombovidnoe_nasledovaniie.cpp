#include<iostream>
#include<fstream>
#include<stdio.h>
#include<unistd.h>
class GeomSerialize
{
    protected:
        bool fl_saved  =false ;
    public:
        GeomSerialize()
        {
            std::cout << "GeomSerialize ctor is called" << std::endl;
        }
        virtual void save(std::ostream& os) const = 0;
        virtual void load(std::istream& is) = 0;
        size_t  get_size_obj() const {return (sizeof(*this));}
        virtual ~GeomSerialize()
        {
            std::cout << "GeomSerialize dtor is called" << std::endl;
        }
};

class GeomBase
{
    protected:
        int x{0}, y{0}, x1{0}, y1{0};
    public:
        GeomBase(int a = 0, int b = 0, int c = 0, int d = 0) :x(a), y(b), x1(c), y1(d)
        {
            std::cout << "GeomBase ctor is called" << std::endl;
        }
        virtual void draw() const = 0;
        virtual ~GeomBase()
        {
            std::cout << "GeomBase dtor is called" << std::endl;
        }
        size_t  get_size_obj() const {return (sizeof(*this));}
};

class Line : public GeomBase, public GeomSerialize
{
    private:
        double length{0.0};
    public:
        Line(int a = 0, int b = 0, int c = 0, int d = 0) : GeomBase(a,b,c,d), GeomSerialize() 
        {
            std::cout << "Line ctor is called" << std::endl;
        }
        virtual void draw() const override
        {
            printf("Line: %d, %d, %d, %d\n", x, y, x1, y1);
        }
        virtual void save(std::ostream& os) const override
        {
            os.write((char *)this, sizeof(*this));
        }
        virtual void load(std::istream& is) override
        {
            is.read((char *)this, sizeof(*this));
        }
        ~Line()
        {
            std::cout << "Line dtor is called" << std::endl;
        }
};

int main()
{
    Line ln(1,2,10,20);

    GeomBase *ptr_b = &ln;
    GeomSerialize *ptr_sz = &ln;//stex uzum ei cuyc tal,vor GeomSerialize-i cucich haytarareluc vory cuyca talu Line-i obj-i var,petq chi grel &(sizeof(GeomBase) + ln), vortev kampilatory ira komic offset-i(zdvig) mijocov apahovuma en vor GeomSerialize-i cucichy cuyc ta vochte Line-i obji-i skzbic(skzbi masum texdrvac en GeomBase-i membernery vorteb demic GeomBase-ic a jarange Line-@ heto GeomSrialize-ic) ayl henc en masic vortexic vor GeomSerialize-i membernery skvum en,u daje sxal klni vor menq anhangstananq vor en sizeof-i pahy dzerov grenq,nenc vor fiqsenq vor petq chi anhanggstanal et pahov,kampilatory tochni tanuma en masi vraya dnum vortexic vor GeomSerialize-i membernery sksvum en!!!!

    
    GeomBase& ref_b = ln;
    GeomSerialize& ref_sz = ln;
    size_t res = ln.get_size_obj();//erb menq GeomBaseum u GeomSerialize-um unenanq pryam nuyn funkcian(get_size_obj) apa kampilaciayi xndir kunenanq,vortev chi jokum vor meki get_size_obj-n kanchi->GeomBase-i te GeomSerialize-i
    //xndiry karanq lucenq ruchnoy snamespace-y nshelov`
    size_t res = ln.GeomBase::get_size_obj();
    //kam karanq parzapes mekum dnenq anuny get_size_obj isk myusum get_size_obj2,bayc kara nenc depq lini vor esel chprli,da hetevyal depqn e`ka mihat General class vorum ktexadrenq et get_size_obj funkcian ev GeomBase-@@ ev GeomSerialize-@ kjarangenq et General-ic,nayir 2.cpp fayl@
}

