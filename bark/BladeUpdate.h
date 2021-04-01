#ifndef __BARK_CORE___BLADE_UPDATE_H__
#define __BARK_CORE___BLADE_UPDATE_H__



namespace bark
{
    namespace core
    {
        typedef enum BLADE_UPDATE
        {
            BLADE_UPDATE_NEW = 0,

            BLADE_UPDATE_SELECTION = 1,
            BLADE_UPDATE_CLEAR_SELECTION = 2,

            BLADE_UPDATE_REPLACEMENT = 3,
            BLADE_UPDATE_INSERTION = 4,
            BLADE_UPDATE_DELETION = 5,

            BLADE_UPDATE_DEPLOYMENT = 6,
            BLADE_UPDATE_CLOSURE = 7
        } BLADE_UPDATE;

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___BLADE_UPDATE_H__