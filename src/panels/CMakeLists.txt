add_library(panels STATIC
        asset_account_panel.cpp
        bank_accounts_panel.cpp
        borrow_give_accounts_panel.cpp
        category_accounts_panel.cpp
        chit_accounts_panel.cpp
        create_accounts.cpp
        credit_card_accounts_panel.cpp
        goal_accounts_panel.cpp
        loan_accounts_panel.cpp
        transactions_panel.cpp
        users_panel.cpp
)
target_include_directories(panels PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})