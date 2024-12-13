add_library(panels STATIC
        models/asset_account_panel.cpp
        models/bank_accounts_panel.cpp
        models/borrow_give_accounts_panel.cpp
        models/category_accounts_panel.cpp
        models/chit_accounts_panel.cpp
        create_accounts.cpp
        models/credit_card_accounts_panel.cpp
        models/goal_accounts_panel.cpp
        models/loan_accounts_panel.cpp
        models/transactions_panel.cpp
        models/users_panel.cpp
        dashboard_panel.cpp
)
target_include_directories(panels PUBLIC .)