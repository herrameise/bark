#include "Bark.h"
using namespace bark::core;

#include "Logger.h"
#include "Manager.h"
#include "Specimen.h"

#include <cstdio>



Bark::Bark()
{
    // components are created in call to Initialize()
}


Bark::~Bark()
{
    delete m_specimen;
    delete m_manager;
    delete m_logger;
}


bool Bark::Initialize()
{
    m_logger = new Logger();
    if (m_logger == nullptr)
    {
        fprintf(stderr, "FATAL: failed to create Logger\n");
        return false;
    }

    m_manager = new Manager(m_logger);
    if (m_manager == nullptr)
    {
        fprintf(stderr, "FATAL: failed to create Manager\n");
        delete m_logger;
        return false;
    }

    m_specimen = new Specimen(m_logger, m_manager);
    if (m_specimen == nullptr)
    {
        fprintf(stderr, "FATAL: failed to create Specimen\n");
        delete m_manager;
        delete m_logger;
        return false;
    }

    m_manager->SetSpecimen(m_specimen);

    return true;
}
