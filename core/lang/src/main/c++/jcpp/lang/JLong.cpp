#include "jcpp/lang/JLong.h"
#include "jcpp/lang/JClass.h"
#include "jcpp/io/JSerializable.h"
#include "jcpp/lang/JByte.h"
#include "jcpp/lang/JStringBuilder.h"
#include "jcpp/lang/reflect/JConstructor.h"
#include "jcpp/lang/reflect/JModifier.h"

using namespace jcpp::lang::reflect;
using namespace jcpp::io;

namespace jcpp{
    namespace lang{

        jint JLong::hashCode(jlong l){
            return (jint)l;
        }

        jint JLong::compare(jlong x,jlong y){
            return x-y;
        }

        JLong* JLong::valueOf(JString* s){
        	return new JLong(s->getNativeString().toJlong());
        }

        JString* JLong::toString(jlong d){
        	return new JString(NativeString::valueOf(d));
        }

        jlong JLong::MIN_VALUE = JLONG_MIN;

        jlong JLong::MAX_VALUE = JLONG_MAX;

        jcpp::lang::JClass* JLong::TYPE = JPrimitiveLong::getClazz();

        jint JLong::SIZE = 64;

        jint JLong::BYTES = SIZE / JByte::SIZE;

        JLong::JLong(jlong value):JNumber(getClazz()){
            this->value=new JPrimitiveLong(value);
        }

        JLong::JLong():JNumber(getClazz()){
            this->value=new JPrimitiveLong(0);
        }

        jbool JLong::equals(JObject* other){
            if ((other != null) && other->getClass()==getClazz()){
                JLong* s=dynamic_cast<JLong*>(other);
                return value->equals(s->value);
            }
            return false;
        }

        void JLong::set(jlong value){
            this->value->set(value);
        }

        jlong JLong::get(){
            return value->get();
        }

        jbyte JLong::byteValue(){
            return (jbyte)value->get();
        }

        jshort JLong::shortValue(){
            return (jshort)value->get();
        }

        jint JLong::intValue(){
            return (jint)value->get();
        }

        jlong JLong::longValue(){
            return value->get();
        }

        jfloat JLong::floatValue(){
            return (jfloat)value->get();
        }

        jdouble JLong::doubleValue(){
            return (jdouble)value->get();
        }

        void JLong::setPrimitiveLong(JPrimitiveLong* value){
            this->value=value;
        }

        JPrimitiveLong* JLong::getPrimitiveLong(){
            return value;
        }

        jint JLong::compareTo(JObject *o){
            JLong* l=dynamic_cast<JLong*>(o);
            return compare(get(),l->get());
        }

        jint JLong::hashCode(){
            return hashCode(value->get());
        }

        JString* JLong::toString(){
            JStringBuilder* builder=new JStringBuilder();
            builder->append(value->get());
            return builder->toString();
        }

        JLong::~JLong(){
        }
    }
}
