add_library(models STATIC
        account.cpp
        asset_account.cpp
        bank_account.cpp
        borrow_give_account.cpp
        category_account.cpp
        chit_account.cpp
        credit_card_account.cpp
        goal_account.cpp
        loan_account.cpp
        transaction.cpp
)
target_include_directories(models PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})