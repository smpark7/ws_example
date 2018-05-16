//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef WS_EXAMPLETESTAPP_H
#define WS_EXAMPLETESTAPP_H

#include "MooseApp.h"

class ws_exampleTestApp;

template <>
InputParameters validParams<ws_exampleTestApp>();

class ws_exampleTestApp : public MooseApp
{
public:
  ws_exampleTestApp(InputParameters parameters);
  virtual ~ws_exampleTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* WS_EXAMPLETESTAPP_H */
