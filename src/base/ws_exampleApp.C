#include "ws_exampleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<ws_exampleApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

ws_exampleApp::ws_exampleApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  ws_exampleApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  ws_exampleApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  ws_exampleApp::registerExecFlags(_factory);
}

ws_exampleApp::~ws_exampleApp() {}

void
ws_exampleApp::registerApps()
{
  registerApp(ws_exampleApp);
}

void
ws_exampleApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"ws_exampleApp"});
}

void
ws_exampleApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"ws_exampleApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
ws_exampleApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
ws_exampleApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
ws_exampleApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ws_exampleApp__registerApps()
{
  ws_exampleApp::registerApps();
}

extern "C" void
ws_exampleApp__registerObjects(Factory & factory)
{
  ws_exampleApp::registerObjects(factory);
}

extern "C" void
ws_exampleApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  ws_exampleApp::associateSyntax(syntax, action_factory);
}

extern "C" void
ws_exampleApp__registerExecFlags(Factory & factory)
{
  ws_exampleApp::registerExecFlags(factory);
}
