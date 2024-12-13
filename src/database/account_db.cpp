// #include <database/account_db.h>
//
// void account_db::add_account(account* acc) {
//   acc->user_id(_user_id);
//   auto acct = std::make_shared<account>("", acc->user_id(), acc->account_type());
//   std::string id = _db.insert(acct);
//   acct.reset();
//   acc->id(id);
//   if (auto bank_acc = std::dynamic_pointer_cast<bank_account>(acc)) {
//     _db.insert(bank_acc);
//   }
// }
//
// void account_db::delete_account(std::shared_ptr<account> acc) {
//   if(auto bank_acc = std::dynamic_pointer_cast<bank_account>(acc)) {
//     _db.remove(bank_acc);
//   }
//   auto acct = std::make_shared<account>(acc->id(), acc->account_type());
//   _db.remove(acct);
// }
//
// void account_db::update_account(std::shared_ptr<account> acc) {
//   if(auto bank_acc = std::dynamic_pointer_cast<bank_account>(acc)) {
//     _db.update(bank_acc);
//   }
//   auto acct = std::make_shared<account>(acc->id(), acc->user_id(), acc->account_type());
//   _db.update(acct);
// }
//
// void account_db::get_account(std::shared_ptr<account> acc) {
//   auto acct = std::make_shared<account>(acc->id());
//   _db.fetch(acct);
//   auto acc_type = acct->account_type();
//   if(auto bank_acc = std::dynamic_pointer_cast<bank_account>(acc)) {
//     _db.fetch(bank_acc);
//     acc->id(acct->id());
//     acc->account_type(acct->account_type());
//   }
// }
//
// std::vector<std::shared_ptr<account>> account_db::get_all_accounts() {
//     std::vector<std::shared_ptr<account>> accounts;
//     auto bank_accounts = get_accounts(enums::account_type::BANK_ACCOUNT);
//     accounts.insert(accounts.end(), bank_accounts.begin(), bank_accounts.end());
//     return accounts;
// }
//
// std::shared_ptr<account> account_db::get_pointer(enums::account_type account_type){
//   if(account_type == enums::account_type::BANK_ACCOUNT) {
//     return std::make_shared<bank_account>();
//   }
//   return nullptr;
// }
//
// std::vector<std::shared_ptr<account>> account_db::get_accounts(enums::account_type account_type) {
//   auto ant = std::make_shared<account>();
//   ant->account_type(account_type);
//   auto accts = _db.select(ant);
//   std::vector<std::shared_ptr<account>> accounts;
//   for(auto acct : accts) {
//     ant = std::make_shared<account>(acct);
//     auto acc = get_pointer(account_type);
//     if(ant->account_type() == account_type) {
//       acc->id(ant->id());
//       acc->account_type(ant->account_type());
//       _db.fetch(acc);
//     }
//     accounts.push_back(acc);
//   }
//   return accounts;
// }
