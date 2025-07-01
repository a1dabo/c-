#include <iostream>
#include <map>
#include <vector>

template<class Key=int,class T=int>
struct pmap
{
    public:
    std::map<Key,T*> inmap;

    pmap()  = default;

    pmap(const std::map<Key,T*>& rmap)
    {

        for(auto& pair:rmap)
        {
            inmap[pair.first]=pair.second;
        }

    }

    ~pmap() {
    for (auto& [key, val] : inmap)
    {
        delete val;
    }
    }



    void pmapprint()
    {
        for(auto& pair:inmap)
        {
            std::cout<<"Key: ["<< pair.first<<"] Value: ["<<*pair.second<<"] Value mem adr: ["<<pair.second<<"]"<<std::endl;
        }
    }

    pmap& operator=(const pmap& other)
    {

        for(auto& pair:other.inmap)
        {
            inmap[pair.first]=pair.second;
        }
        return *this;
    }
    
    pmap& operator=(const std::map<Key,T*>& rmap)
    {

        for(auto& pair:rmap)
        {
            inmap[pair.first]=pair.second;
        }
        return *this;

    }

    pmap operator+(const pmap& other) const
    {   
    pmap result;

    for (auto& [key, val] : this->inmap)
    {
        if (other.inmap.count(key))
        {
            // új érték, külön memória
            T* newVal = new T(*val + *other.inmap.at(key));
            result.inmap[key] = newVal;
        }
    }

    return result;
    }


    T get(Key k)
    {
        return *inmap[k];
    }



};


void print(const int& n)
{
    std::cout<< n << ' ';
}

std::map<int,int*> copy(std::map<int,int>& map)
{
    std::map<int,int*> retmap;
    for (auto& pair:map)
    {
        retmap[pair.first+10]=&pair.second;
    }
    return retmap;
}

std::map<int,int*> copy2(std::map<int,int>& map)
{
    std::map<int,int*> retmap;
    for (auto& pair:map)
    {
        retmap.insert(std::make_pair(pair.first,&pair.second));
    }
    return retmap;
}

void setkey(const int& n,std::map<int,int*>& map)
{
int sum=0;
for(auto& pair: map)
{
if(pair.first==n)
{
    break;
}
sum=sum+*pair.second;
*pair.second=sum;

}

}

const int max=10;

int main()
{


    std::map<int,int> map;

    for (size_t i = 0; i < max; i++)
    {
        map[i+10]=i;
    }

    for(auto& pair :map)
    {
        print(pair.second);
    }
    
    for (auto map_iterator = map.begin(); map_iterator != map.end(); map_iterator++)
    {
     print(map_iterator->first);
    }

    std::cout<< std::endl;

    std::vector<int> intVector = {10, 20, 30, 40, 50};
    std::vector<int*> pintvec;
    for (auto& data : intVector)
    {
        pintvec.push_back(&data);
    }

    std::map<int,int*> cmap = copy(map);
    
    for (auto map_iterator = cmap.begin(); map_iterator != cmap.end(); map_iterator++)
    {
     print(map_iterator->first);
    }

    std::cout<< std::endl;
    cmap = copy(map);

    int sum=0;
    for (auto& pair : map)
    {
        pair.second=1;
        sum+=pair.second;
        pair.second=sum;
    }

    setkey(5,cmap);
    
    for(auto& pair : cmap)
    {
        print(*pair.second);
    }

    pmap a;
    pmap b=cmap;
    a=b;

    a.pmapprint();

    pmap<int,int> c=a+b;
    
    b.pmapprint();

    c.pmapprint();
}