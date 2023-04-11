#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <limits>

#include <utility>
#include <map>

#include <typeinfo>



class Contents
{
  public:
    Contents()
    { printf("Contents constructor\n"); };

    virtual ~Contents()
    { printf("Contents destructor\n"); };
};



template <class T>
class ContentsType: public Contents
{
  private:
    T *value_;

  public:
    ContentsType(T value):
      value_(NULL)
    {
      printf("ContentsType constructor: type: %s\n", typeid(value).name());
      set(value);
    }

    ~ContentsType()
    {
      printf("~ContentsType destructor\n");
      clear();
    }

    void clear()
    {
      if(value_ != NULL)
      {
        printf("ContentsType: clear: %s\n", typeid(value_).name());
        delete value_;
        value_ = NULL;
      }
    }

    T get()
    {
      return *value_;
    }

    void set(T value)
    {
      clear();

      T *p_ = new T(value);
      value_ = p_;
    }
};



class Container
{
  private:
    Contents *contents_;

  public:
    Container(Contents *contents):
    contents_(contents)
    {
      printf("Container constructor\n");
    };

    ~Container()
    {
      printf("\nContainer destructor\n");
      delete contents_;
    };

    template< typename T >
    T get()
    {
      return static_cast< ContentsType< T > * >(contents_)->get();
    };

    template< typename T >
    void set(T value)
    {
      static_cast< ContentsType< T > * >(contents_)->set(value);
    };
};



class Train
{
  private:
    std::map< std::string, Container * > pod;

  public:
    Train()
      { printf("Train constructor\n"); };

    ~Train()
      {
        printf("Train destructor\n");
        for(std::map< std::string, Container * >::iterator itr = pod.begin(); itr != pod.end(); ++itr)
          delete itr->second;
      };

    template< typename T >
    void set(std::string name, T value)
    {
      std::map< std::string, Container * >::iterator itr = pod.find(name);

      if(itr == pod.end())
      {
        Contents *contents_ = new ContentsType(value);
        pod.insert(std::make_pair< std::string, Container * >(name.c_str(), new Container(contents_)));
      }
      else
        pod[name.c_str()]->set(value);
    }

    template< typename T >
    T get(std::string name)
    {
      T var_ = 0;

      std::map< std::string, Container * >::iterator itr = pod.find(name);
      if(itr != pod.end())
        var_ = pod[name.c_str()]->get< T >();

      return var_;
    }
};



#endif
