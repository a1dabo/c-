  #include <string>
  #include <iostream>

  class safe_string: public std::string
  {
    public:
    safe_string(const char* p): std::string(p?p:""){}
  };

  int main()
  {
    safe_string s(0);
    safe_string word("bangedr");
    s.push_back('a');
    word.push_back('!');
    std::cout<<"size: "<<s.size()<<" word : "<<s<<std::endl;
    std::cout<< "size: "<<word.size()<<" word : "<<word<<std::endl;
  }