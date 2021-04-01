#ifndef __BARK_CORE___BLADE_UPDATE_H__
#define __BARK_CORE___BLADE_UPDATE_H__



namespace bark
{
    namespace core
    {
        typedef enum BLADE_UPDATE
        {
            BLADE_UPDATE_NEW = 0,               //!< A new specimen was created or loaded from file.

            BLADE_UPDATE_SELECTION = 1,         //!< The selection range changed.
            BLADE_UPDATE_CLEAR_SELECTION = 2,   //!< The selection was cleared.

            BLADE_UPDATE_REPLACEMENT = 3,       //!< Bytes were replaced in the specimen.
            BLADE_UPDATE_INSERTION = 4,         //!< Bytes were inserted into the specimen.
            BLADE_UPDATE_DELETION = 5,          //!< Bytes were deleted from the specimen.

            BLADE_UPDATE_DEPLOYMENT = 6,        //!< A new blade was deployed. All blades should recheck their dependents/dependees.
            BLADE_UPDATE_CLOSURE = 7            //!< A deployed blade was closed. All blades should recheck their dependents/dependees.
        } BLADE_UPDATE;
    }
}



#endif // __BARK_CORE___BLADE_UPDATE_H__