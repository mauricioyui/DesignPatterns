#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <limits>

#include <utility>
#include <map>

#include <typeinfo>


template <class T>
class Contents
{
  private:
    T *value;

  public:
    Contents(T value_):
      value(NULL)
    {
      printf("Contents constructor: type: %s\n", typeid(value_).name());
      set(value_);
      printf("Contents constructor: end\n");
    }

    ~Contents()
    {
      printf("~Contents destructor\n");
      clear();
    }

    void clear()
    {
      printf("Contents clear: 01\n");
      if(value != NULL)
      {
        printf("Contents clear: %s\n", typeid(value).name());
        delete value;
        value = NULL;
      }
      printf("Contents clear: 03\n");
    }

    void * get()
    {
      return static_cast< void * >(value);
    }

    void set(T value_)
    {
      printf("Contents set: 01\n");
      T *p_ = (T *)malloc(sizeof(T));
      printf("Contents set: 02\n");
      *p_ = value_;
      printf("Contents set: 03\n");

      clear();
      printf("Contents set: 04\n");

      value = p_;
      printf("Contents set: 05\n");
    }
};



class Container
{
  private:
    void *contents;

  public:
    Container(void *contents_):
    contents(contents_)
    {
      printf("Container constructor\n");
    };

    ~Container()
    {
      printf("Container destructor\n");
    };

    void * get()
    {
      return contents;
      // int dummy = 0;
      // return static_cast< Contents< dummy > * >(contents)->get();
    };

    // template< typename T >
    // T get()
    // {
    //   // return *static_cast< T * >(static_cast< Contents< T > * >(contents)->get());
    //   T t_ = *static_cast< Contents< T > * >(contents)->get();
    //   return t_;
    // };

    template< typename T >
    void set(T value_)
    {
      // (Contents< T >*)contents->set(value_);
      static_cast< Contents< T > * >(contents)->set(value_);
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
        {
          delete itr->second;
        };
      };

    template< typename T >
    void set(std::string name_, T value_)
    {
      std::map< std::string, Container * >::iterator itr = pod.find(name_);

      if(itr == pod.end())
      {
        void *contents_ = new Contents(value_);
        pod.insert(std::make_pair< std::string, Container * >(name_.c_str(), new Container(contents_)));
      }
      else
      {
        pod[name_.c_str()]->set(value_);
      }
    }

    template< typename T >
    T get(std::string name_)
    {
      T var_ = 0;

      std::map< std::string, Container * >::iterator itr = pod.find(name_);
      if(itr != pod.end())
      {
        Container *container_ = pod[name_.c_str()];
        Contents< T > * contents_ = static_cast< Contents< T > * >(container_->get());

        var_ = *(static_cast< T * >(contents_->get()));
      }
      return var_;
    }

    template< typename T >
    void clear(std::string name_)
    {
      std::map< std::string, Container * >::iterator itr = pod.find(name_);
      if(itr != pod.end())
      {
        Container *container_ = pod[name_.c_str()];
        Contents< T > * contents_ = static_cast< Contents< T > * >(container_->get());
        contents_->clear();
      }
    }
};

#endif
