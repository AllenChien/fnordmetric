/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * Licensed under the MIT license (see LICENSE).
 */
#ifndef _FNORDMETRIC_DIMENSION_H
#define _FNORDMETRIC_DIMENSION_H

#include <stdlib.h>
#include <string>

namespace fnordmetric {
class Agent;

class IDimension {
public:

  enum kDimensionType {
    INT64  = 'I',
    IEE754 = 'F',
    STRING = 'S'
  };

  IDimension(kDimensionType type, const std::string& name) :
      type_(type),
      name_(name) {}


  virtual ~IDimension() {}

  const std::string& getName() const {
    return name_;
  }

  kDimensionType getTypeId() const {
    return type_;
  }

protected:

  kDimensionType type_; // FIXPAUL REMOVE ME
  std::string name_;
};


class IntegerDimension : public IDimension {
public:
  IntegerDimension(const std::string& name) :
      IDimension(IDimension::INT64, name) {}

  typedef int64_t ValueType;
};

}
#endif
