#ifndef COMMAND_H
#define COMMAND_H

#include <QDebug>

class Group
{
public:
    Group();
    virtual void find() = 0;
    virtual void add() = 0;
    virtual void del() = 0;
    virtual void plan() = 0;
    virtual void back() = 0;
};

class RequirementGroup : public Group
{
public:
    RequirementGroup();
    virtual void find();
    virtual void add();
    virtual void del();
    virtual void plan();
    virtual void back();
};

class PageGroup : public Group
{
public:
    PageGroup();
    virtual void find();
    virtual void add();
    virtual void del();
    virtual void plan();
    virtual void back();
};

class CodeGroup : public Group
{
public:
    CodeGroup();
    virtual void find();
    virtual void add();
    virtual void del();
    virtual void plan();
    virtual void back();
};

class Command
{
public:
    Command();

    virtual void execute() = 0;

protected:
    RequirementGroup *_requirementGroup;
    PageGroup *_pageGroup;
    CodeGroup *_codeGroup;
};

class AddRequirementCommand : public Command
{
public:
    AddRequirementCommand();
    virtual void execute();
};

class DelPageCommand : public Command
{
public:
    DelPageCommand();
    virtual void execute();
};

class BackCommand : public Command
{
public:
    BackCommand();
    virtual void execute();
};

class Invoker
{
public:
    Invoker();
    Invoker(Command *command);

    Command *command() const;
    void setCommand(Command *command);

    void test();

private:
    Command *_command;
};

#endif // COMMAND_H
