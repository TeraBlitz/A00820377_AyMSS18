import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { RecetasEditComponent } from './recetas-edit.component';

describe('RecetasEditComponent', () => {
  let component: RecetasEditComponent;
  let fixture: ComponentFixture<RecetasEditComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ RecetasEditComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(RecetasEditComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
