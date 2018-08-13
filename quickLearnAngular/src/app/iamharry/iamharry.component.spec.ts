import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { IamharryComponent } from './iamharry.component';

describe('IamharryComponent', () => {
  let component: IamharryComponent;
  let fixture: ComponentFixture<IamharryComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ IamharryComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(IamharryComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
