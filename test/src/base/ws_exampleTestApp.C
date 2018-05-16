//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ws_exampleTestApp.h"
#include "ws_exampleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<ws_exampleTestApp>()
{
  InputParameters params = validParams<ws_exampleApp>();
  return params;
}

ws_exampleTestApp::ws_exampleTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ws_exampleApp::registerObjectDepends(_factory);
  ws_exampleApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ws_exampleApp::associateSyntaxDepends(_syntax, _action_factory);
  ws_exampleApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  ws_exampleApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    ws_exampleTestApp::registerObjects(_factory);
    ws_exampleTestApp::associateSyntax(_syntax, _action_factory);
    ws_exampleTestApp::registerExecFlags(_factory);
  }
}

ws_exampleTestApp::~ws_exampleTestApp() {}

void
ws_exampleTestApp::registerApps()
{
  registerApp(ws_exampleApp);
  registerApp(ws_exampleTestApp);
}

void
ws_exampleTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
ws_exampleTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
ws_exampleTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ws_exampleTestApp__registerApps()
{
  ws_exampleTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
ws_exampleTestApp__registerObjects(Factory & factory)
{
  ws_exampleTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
ws_exampleTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ws_exampleTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
ws_exampleTestApp__registerExecFlags(Factory & factory)
{
  ws_exampleTestApp::registerExecFlags(factory);
}
