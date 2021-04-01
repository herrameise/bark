#ifndef __BARK_CORE___BLADE_DEPLOYMENT_H__
#define __BARK_CORE___BLADE_DEPLOYMENT_H__



namespace bark
{
    namespace core
    {
        class Blade;
        class BladeEntry;

        class BladeDeployment
        {
        public:
            Blade*          blade;
            BladeEntry*     entry;
        };
    }
}



#endif // __BARK_CORE___BLADE_DEPLOYMENT_H__