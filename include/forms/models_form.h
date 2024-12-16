#pragma once

class model_form{
public:
  virtual ~model_form() = default;
  virtual void save() = 0;
};