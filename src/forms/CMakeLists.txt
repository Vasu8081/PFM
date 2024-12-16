add_library(forms STATIC
        asset_account_form.cpp
        bank_account_form.cpp
        borrow_give_account_form.cpp
        category_account_form.cpp
        chit_account_form.cpp
        credit_card_account_form.cpp
        goal_account_form.cpp
        loan_account_form.cpp
        transaction_form.cpp
        user_form.cpp
        income_form.cpp
)
target_include_directories(forms PUBLIC .)