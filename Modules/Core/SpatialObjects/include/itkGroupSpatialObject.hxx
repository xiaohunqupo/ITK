/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkGroupSpatialObject_hxx
#define itkGroupSpatialObject_hxx


namespace itk
{
/** Constructor */
template <unsigned int TDimension>
GroupSpatialObject<TDimension>::GroupSpatialObject()
{
  this->SetTypeName("GroupSpatialObject");
}

/** InternalClone */
template <unsigned int TDimension>
typename LightObject::Pointer
GroupSpatialObject<TDimension>::InternalClone() const
{
  // Default implementation just copies the parameters from
  // this to new transform.
  typename LightObject::Pointer loPtr = Superclass::InternalClone();

  typename Self::Pointer rval = dynamic_cast<Self *>(loPtr.GetPointer());
  if (rval.IsNull())
  {
    itkExceptionMacro(<< "downcast to type " << this->GetNameOfClass() << " failed.");
  }

  return loPtr;
}

} // end namespace itk

#endif // end itkGroupSpatialObject_hxx
