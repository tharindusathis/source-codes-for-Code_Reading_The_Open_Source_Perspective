//
// Stock_Consumer.cpp,v 1.3 2001/03/29 19:42:06 coryan Exp
//

#include "Stock_Consumer.h"
#include "QuoterC.h"

Stock_Consumer::Stock_Consumer ()
{
}

void
Stock_Consumer::connect (CosEventChannelAdmin::EventChannel_ptr event_channel)
{
  CosEventChannelAdmin::ConsumerAdmin_var consumer_admin =
    event_channel->for_consumers ();

  this->supplier_proxy_ =
    consumer_admin->obtain_push_supplier ();

  CosEventComm::PushConsumer_var myself = this->_this ();
  this->supplier_proxy_->connect_push_consumer (myself.in ());
}

void
Stock_Consumer::disconnect ()
{
  // Do not receive any more events...
  this->supplier_proxy_->disconnect_push_supplier ();
}

void
Stock_Consumer::push (const CORBA::Any& data,
                      CORBA::Environment &)
  throw (CORBA::SystemException)
{
  Quoter::Event *event;
  if ((data >>= event) == 0)
    return; // Invalid event

  cout << "The new price for one stock in \""
       << event->full_name.in ()
       << "\" (" << event->symbol.in ()
       << ") is " << event->price << endl;
}

void
Stock_Consumer::disconnect_push_consumer (CORBA::Environment &)
    throw (CORBA::SystemException)
{
  this->supplier_proxy_ = CosEventChannelAdmin::ProxyPushSupplier::_nil ();
}
