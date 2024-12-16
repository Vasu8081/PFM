add_library(panels STATIC
        create_accounts.cpp
        dashboard_panel.cpp
        transactions_panel.cpp
)
target_include_directories(panels PUBLIC .)