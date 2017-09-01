#include "command.h"

Command::Command()
{
    _requirementGroup = new RequirementGroup;
    _pageGroup = new PageGroup;
   _codeGroup = new  CodeGroup;
}



Group::Group()
{

}


RequirementGroup::RequirementGroup()
{

}

void RequirementGroup::find()
{
    qDebug() << "RequirementGroup find";
}

void RequirementGroup::add()
{
    qDebug() << "RequirementGroup add";
}

void RequirementGroup::del()
{
    qDebug() << "RequirementGroup del";
}

void RequirementGroup::plan()
{
    qDebug() << "RequirementGroup plan";
}

void RequirementGroup::back()
{
    qDebug() << "RequirementGroup back";
}


PageGroup::PageGroup()
{

}

void PageGroup::find()
{
    qDebug() << "PageGroup find";
}

void PageGroup::add()
{
    qDebug() << "PageGroup add";
}

void PageGroup::del()
{
    qDebug() << "PageGroup del";
}

void PageGroup::plan()
{
    qDebug() << "PageGroup plan";
}

void PageGroup::back()
{
    qDebug() << "PageGroup back";
}


CodeGroup::CodeGroup()
{

}

void CodeGroup::find()
{
    qDebug() << "CodeGroup find";
}

void CodeGroup::add()
{
    qDebug() << "CodeGroup add";
}

void CodeGroup::del()
{
    qDebug() << "CodeGroup del";
}

void CodeGroup::plan()
{
    qDebug() << "CodeGroup plan";
}

void CodeGroup::back()
{
    qDebug() << "CodeGroup back";
}


AddRequirementCommand::AddRequirementCommand()
{

}

void AddRequirementCommand::execute()
{
    _requirementGroup->find();
    _requirementGroup->add();
    _requirementGroup->plan();
}


DelPageCommand::DelPageCommand()
{

}

void DelPageCommand::execute()
{
    _pageGroup->find();
    _pageGroup->del();
    _pageGroup->plan();
}

Invoker::Invoker()
{

}

Invoker::Invoker(Command *command)
{
    _command = command;
}

Command *Invoker::command() const
{
    return _command;
}

void Invoker::setCommand(Command *command)
{
    _command = command;
}

void Invoker::test()
{
    _command->execute();
}


BackCommand::BackCommand()
{

}

void BackCommand::execute()
{
    _requirementGroup->back();
    _pageGroup->back();
    _codeGroup->back();
}
