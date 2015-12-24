#ifndef MQPOOL_INCLUDE_MESSAGEQUEUE_H_
#define MQPOOL_INCLUDE_MESSAGEQUEUE_H_

#include "object.h"
#include "message_factory.h"
#include <string>

using std::string;

class MessageQueue : public Object {
 public:
  explicit MessageQueue();
  explicit MessageQueue(string msgFile);
  MessageQueue(const MessageQueue&) = delete;
  MessageQueue& operator=(const MessageQueue&) = delete;
  virtual ~MessageQueue();

  void Dump() const;

  int GetMsgID() const;

  string GetMsgFile() const;

  /*
   * 设置了msgFile_之后，连带生成新的msgid_
   */
  void SetMsgFile(const string& msgFile);

  int SendMsg(struct myMsg* messagePtr);

  int RecvMsg(long type, struct myMsg* messagePtr);

  void DeleteMsgQue();

 private:
  int msgid_;

  //用于ftok的msgFile_
  string msgFile_;

};

#endif /* MQPOOL_INCLUDE_MESSAGEQUEUE_H_ */
